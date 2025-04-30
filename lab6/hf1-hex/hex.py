import sys
import heapq
import re

sys.setrecursionlimit(10000)

INFTY = 10**9

class Coord:
    def __init__(self, x=0, y=0):
        self.x = x
        self.y = y

    def __add__(self, other):
        return Coord(self.x + other.x, self.y + other.y)

    def __str__(self):
        return f"({self.x+1},{self.y+1})"

    @staticmethod
    def from_input(s):
        nums = re.findall(r'\d+', s)
        if len(nums) < 2:
            raise ValueError("Invalid coordinate input")
        a, b = map(int, nums[:2])
        return Coord(a-1, b-1)

class Command:
    undo_default = 1

    def __init__(self, undo_steps=0, c=None):
        self.undo_steps = undo_steps
        self.c = c or Coord()

    @classmethod
    def undo(cls, undo_steps=None):
        if undo_steps is None:
            undo_steps = cls.undo_default
        return cls(undo_steps, Coord())

class Player:
    def __init__(self, turn):
        self.turn = turn  # 0=x vertical, 1=o horizontal

    def is_human(self):
        return False

    def move(self, board):
        raise NotImplementedError

    def opponent_move(self, board, c):
        pass

class Human(Player):
    def is_human(self):
        return True

    def move(self, board):
        while True:
            line = input()
            if not line:
                continue
            line = line.strip()
            if line.startswith('u'):
                parts = line.split()
                if len(parts) > 1 and parts[1].isdigit():
                    steps = int(parts[1])
                else:
                    steps = Command.undo_default
                return Command.undo(steps)
            try:
                c = Coord.from_input(line)
                return Command(0, c)
            except:
                continue

    def opponent_move(self, board, c):
        pass

class HexGame:
    def __init__(self, n, p0, p1):
        self.n = n
        self.board = [[-1]*n for _ in range(n)]
        self.history = []
        self.p0 = p0
        self.p1 = p1
        if p0.is_human() != p1.is_human():
            Command.undo_default = 2
        else:
            Command.undo_default = 1

    def is_inside(self, c):
        return 0 <= c.x < self.n and 0 <= c.y < self.n

    def check_win(self, p):
        visited = [[False]*self.n for _ in range(self.n)]
        dirs = [Coord(-1,0), Coord(-1,1), Coord(0,-1),
                Coord(0,1), Coord(1,-1), Coord(1,0)]
        
        def path(c):
            if p==0 and c.x==self.n:
                return True
            if p==1 and c.y==self.n:
                return True
            if not self.is_inside(c):
                return False
            if self.board[c.x][c.y] != p:
                return False
            if visited[c.x][c.y]:
                return False
            visited[c.x][c.y] = True
            for d in dirs:
                if path(c+d):
                    return True
            return False
        for i in range(self.n):
            s = Coord(0, i) if p==0 else Coord(i, 0)
            if self.board[s.x][s.y] == p and path(s):
                return True
        return False

    def get_token(self, x, y):
        if self.board[x][y] == -1:
            return '.'
        p = self.board[x][y]
        r = len(self.history)
        normal = 'o' if p else 'x'
        last = 'O' if p else 'X'
        if r>0 and self.history[r-1].x==x and self.history[r-1].y==y:
            return last
        if r>1 and self.history[r-2].x==x and self.history[r-2].y==y:
            return last
        return normal

    def print_board(self):
        print()
        header = '   ' + ''.join(f"{j+1:>4}" for j in range(self.n))
        print(header)
        for i in range(self.n):
            row = f"{i+1:>2}{' '*(2*i+1)}"
            for j in range(self.n):
                row += f"{self.get_token(i,j):>4}"
            print(row)
        print()

    def run(self):
        self.print_board()
        print("Welcome to HEX!\n")
        print("Human players:")
        print("  - Move by typing (x,y) coordinates in any format.")
        print("  - Undo the last human move with 'u'.")
        print("    - Or specify how many moves to undo with 'u <num>', i.e. 'u 5'.\n")
        while True:
            r = len(self.history)
            player = self.p1 if r%2 else self.p0
            enemy = self.p0 if r%2 else self.p1
            name = "Horizontal (o)" if player.turn else "Vertical (x)"
            print(f"{name} move: ", end='', flush=True)
            mv = player.move(self.board)
            if mv.undo_steps:
                if not self.history:
                    print("No history to undo!")
                    continue
                steps = min(mv.undo_steps, len(self.history))
                print(f"Undoing last {steps} move(s)...")
                for _ in range(steps):
                    c = self.history.pop()
                    self.board[c.x][c.y] = -1
                self.print_board()
                continue
            c = mv.c
            print(c, end='')
            if not self.is_inside(c):
                print(" is outside of bounds!")
                continue
            if self.board[c.x][c.y] != -1:
                print(" is an occupied cell!")
                continue
            print(" is ok.")
            self.history.append(c)
            self.board[c.x][c.y] = player.turn
            enemy.opponent_move(self.board, c)
            self.print_board()
            if self.check_win(player.turn):
                print(f"{name} player wins!")
                break

class Graph:
    def __init__(self, board):
        n = len(board)
        size = n*n + 4
        self.mat = [[0]*size for _ in range(size)]
        self.color = [-1]*size
        self.which = [Coord(-1,-1) for _ in range(size)]
        self.s0 = n*n
        self.t0 = n*n+1
        self.s1 = n*n+2
        self.t1 = n*n+3
        self.color[self.s0] = 0
        self.color[self.t0] = 0
        self.color[self.s1] = 1
        self.color[self.t1] = 1
        dirs = [Coord(-1,0), Coord(-1,1), Coord(0,-1),
                Coord(0,1), Coord(1,-1), Coord(1,0)]
        def idx(c):
            return c.x * n + c.y
        def inside(c):
            return 0 <= c.x < n and 0 <= c.y < n

        def add_edge(v, u):
            if v<0 or v>=size or u<0 or u>=size:
                raise ValueError("vertex doesn't exist")
            self.mat[v][u] = 1
            self.mat[u][v] = 1

        for i in range(n):
            add_edge(self.s0, idx(Coord(0,i)))
            add_edge(self.t0, idx(Coord(n-1,i)))
            add_edge(self.s1, idx(Coord(i,0)))
            add_edge(self.t1, idx(Coord(i,n-1)))
        for x in range(n):
            for y in range(n):
                c = Coord(x,y)
                i = idx(c)
                self.color[i] = board[x][y]
                self.which[i] = c
                for d in dirs:
                    cd = c + d
                    if inside(cd):
                        add_edge(i, idx(cd))

    def shortest_path(self, turn):
        if turn==0:
            s, t, incl, excl = self.s0, self.t0, 0, 1
        elif turn==1:
            s, t, incl, excl = self.s1, self.t1, 1, 0
        else:
            raise ValueError("incorrect turn")
        size = len(self.mat)
        p = [-1]*size
        p[s] = -2
        d = [INFTY]*size
        d[s] = 0
        heap = [(0, s)]
        while heap:
            dv, v = heapq.heappop(heap)
            if d[v] < dv:
                continue
            for u in range(size):
                if self.color[u]==excl or self.mat[v][u]==0:
                    continue
                w = 0 if self.color[u]==incl else 1
                du = dv + w
                if du < d[u]:
                    d[u] = du
                    p[u] = v
                    heapq.heappush(heap, (du, u))
        if d[t] == INFTY:
            raise RuntimeError("no path")
        path = []
        curr = t
        while curr != s:
            path.append(curr)
            curr = p[curr]
        path.append(s)
        path.reverse()
        ans = []
        for i in range(1, len(path)-1):
            u = path[i]
            if self.color[u] != -1:
                continue
            ans.append(self.which[u])
        return ans

class BaseBot(Player):
    def move(self, board):
        g = Graph(board)
        player = g.shortest_path(0)
        enemy = g.shortest_path(1)
        if self.turn:
            player, enemy = enemy, player
        if not player or not enemy:
            raise RuntimeError("no available moves")
        if len(player) < len(enemy):
            ans = player[len(player)//2]
        else:
            ans = enemy[len(enemy)//2]
        return Command(0, ans)

    def opponent_move(self, board, c):
        pass

class YourBot(Player):
    def move(self, board):
        raise NotImplementedError("not implemented")

    def opponent_move(self, board, c):
        pass

def pick_type(turn):
    name = "Horizontal (o)" if turn else "Vertical (x)"
    print(f"Pick a type for {name} player:")
    print("(0) Human")
    print("(1) Base bot")
    print("(2) Your bot (to be implemented)")
    t = int(input("Pick: "))
    if t == 0:
        return Human(turn)
    elif t == 1:
        return BaseBot(turn)
    elif t == 2:
        return BaseBot(turn)
    else:
        raise ValueError("Invalid type selected")

def main():
    n = int(input("Board size: "))
    p0 = pick_type(0)
    p1 = pick_type(1)
    game = HexGame(n, p0, p1)
    game.run()

if __name__ == "__main__":
    main()
