#include<algorithm>
#include<vector>
#include<iostream>
#include<functional>
#include<iomanip>
#include<queue>
#include<limits>
using namespace std;

const int infty = 1e9;

void reset(istream& in)
{
  in.clear();
  in.ignore(numeric_limits<streamsize>::max(), '\n');
}

struct coord
{
  int x, y;
  coord operator+(const coord& o) { return { x + o.x, y + o.y }; }
  friend ostream& operator<<(ostream& out, const coord& c)
  {
    return out << "(" << c.x + 1 << "," << c.y + 1 << ")";
  }
  friend istream& operator>>(istream& in, coord& c)
  {
    int a, b;
    while (!(in >> a)) { in.clear(); in.ignore(1); }
    while (!(in >> b)) { in.clear(); in.ignore(1); }
    --a; --b; c = { a,b };
    return in;
  }
};

struct command
{
  static int undo_default;
  int undo_steps;
  coord c;
  command(int undo_steps, coord c) : undo_steps(undo_steps), c(c) {}
  command(coord c) : undo_steps(0), c(c) {}
  static command undo() { return { undo_default, {} }; }
  static command undo(int undo_steps) { return { undo_steps, {} }; }
};
int command::undo_default = 1;

struct player
{
  const int turn; // 0 = Vertical (x), 1 = Horizontal (o)
  player(int turn) : turn(turn) {}
  virtual bool is_human() const { return false; }

  virtual command move(const vector<vector<int>>& board) = 0;
  virtual void opponent_move(const vector<vector<int>>& board, const coord& c) = 0;
  virtual ~player() {}
};

struct human : public player
{
  using player::player;
  virtual bool is_human() const { return true; }
  virtual command move(const vector<vector<int>>& board)
  {
    while (true)
    {
      if (cin.peek() == 'u')
      {
        cin.ignore(1);
        while (cin.peek() != '\n' && !isdigit(cin.peek())) cin.ignore(1);
        int x = command::undo_default; if (isdigit(cin.peek())) cin >> x;
        reset(cin);
        return command::undo(x);
      }
      if (isdigit(cin.peek())) { coord c; cin >> c; reset(cin); return c; }
      cin.ignore(1);
    }
  }
  virtual void opponent_move(const vector<vector<int>>& board, const coord& c)
  {
    // yolo
  }
};

class hex_game
{
private:
  const int n;
  vector<vector<int>> board;
  vector<coord> history;
  player& p0, & p1;

public:
  hex_game(int n, player& p0, player& p1) : n(n), board(n, vector<int>(n, -1)), p0(p0), p1(p1)
  {
      if (p0.is_human() != p1.is_human()) command::undo_default = 2;
      else command::undo_default = 1;
  }

  bool is_inside(coord c) const { return (0 <= c.x && c.x < n) && (0 <= c.y && c.y < n); }

  bool check_win(int p)
  {
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    vector<coord> dirs = { {-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0} };
    function<bool(int, coord)> path = [&](int p, coord c)
    {
      if (p == 0 && c.x == n || p == 1 && c.y == n) return true;
      if (!is_inside(c)) return false;
      if (board[c.x][c.y] != p) return false;
      if (visited[c.x][c.y]) return false;
      visited[c.x][c.y] = true;
      for (auto& dir : dirs) if (path(p, c + dir)) return true;
      return false;
    };
    for (int i = 0; i < n; ++i)
    {
      auto s = coord{ p * i,(1 - p) * i };
      if (board[s.x][s.y] == p && path(p, s)) return true;
    }
    return false;
  }

  char get_token(int x, int y)
  {
    if (board[x][y] == -1) return '.';
    int p = board[x][y];
    int round = history.size();
    int turn = round % 2;

    char normal = (p ? 'o' : 'x');
    char last = (p ? 'O' : 'X');

    if (0 < round && history[round - 1].x == x && history[round - 1].y == y) return last;
    if (1 < round && history[round - 2].x == x && history[round - 2].y == y) return last;
    return normal;
  }

  void print_board()
  {
    cout << endl;
    cout << string(3, ' ');
    for (int j = 0; j < n; ++j) cout << setw(4) << j + 1;
    cout << endl;
    for (int i = 0; i < n; ++i)
    {
      cout << setw(2) << i + 1 << string(2 * i + 1, ' ');
      for (int j = 0; j < n; ++j) cout << setw(4) << get_token(i, j);
      cout << endl;
    }
    cout << endl;
  }

  void run()
  {
    print_board();

    cout << "Welcome to HEX!" << endl;
    cout << endl;
    cout << "Human players:" << endl;
    cout << "  - Move by typing (x,y) coordinates in any format." << endl;
    cout << "  - Undo the last human move with 'u'." << endl;
    cout << "    - Or specify how many moves to undo with 'u <num>', i.e. 'u 5'." << endl;
    cout << endl;

    while (true)
    {
      int round = history.size();
      auto& player = round % 2 ? p1 : p0;
      auto& enemy = round % 2 ? p0 : p1;
      string name = player.turn ? "Horizontal (o)" : "Vertical (x)";

      cout << name << " move: " << flush;
      auto move = player.move(board);

      if (move.undo_steps)
      {
        if (history.empty()) { cout << "No history to undo!" << endl; continue; }
        move.undo_steps = min(move.undo_steps, (int)history.size());
        cout << "Undoing last " << move.undo_steps << " move(s)..." << endl;
        for (int i = 0; i < move.undo_steps; ++i)
        {
          auto& c = history.back(); history.pop_back();
          board[c.x][c.y] = -1;
        }
        print_board();
        continue;
      }

      auto& c = move.c;
      cout << c;
      if (!is_inside(c)) { cout << " is outside of bounds!" << endl; continue; }
      if (board[c.x][c.y] != -1) { cout << " is an occupied cell!" << endl; continue; }
      cout << " is ok." << endl;

      history.push_back(c);
      board[c.x][c.y] = player.turn;
      enemy.opponent_move(board, c);
      print_board();

      if (check_win(player.turn)) { cout << name << " player wins!" << endl; break; }
    }
  }
};

using heap_data = pair<int, int>;
using min_heap = priority_queue<heap_data, vector<heap_data>, greater<heap_data>>;
struct graph
{
  int s0, t0; // vertical start / end
  int s1, t1; // horizontal start / end

  vector<vector<int>> mat;
  vector<int> color;
  vector<coord> which;

  int n() { return mat.size(); }

  void add_edge(int v, int u)
  {
    if (v < 0 || n() <= v) throw invalid_argument("graph vertex doesn't exist");
    if (u < 0 || n() <= u) throw invalid_argument("graph vertex doesn't exist");
    mat[v][u] = 1;
    mat[u][v] = 1;
  }

  vector<coord> shortest_path(int turn)
  {
    int s, t, incl, excl;
    if (turn == 0) { s = s0; t = t0; incl = 0; excl = 1; }
    else if (turn == 1) { s = s1; t = t1; incl = 1; excl = 0; }
    else throw invalid_argument("incorrect turn");

    vector<int> p(n(), -1);     p[s] = -2;
    vector<int> d(n(), infty);  d[s] = 0;
    min_heap q; q.push({ 0, s });

    while (!q.empty())
    {
      pair<int, int> x = q.top();
      int dv = x.first;
      int v = x.second;
      q.pop();

      if (d[v] < dv) continue;
      for (int u = 0; u < n(); ++u)
      {
        if (color[u] == excl) continue;
        if (!mat[v][u]) continue;
        int w = color[u] != incl;
        auto du = dv + w;
        if (d[u] <= du) continue;
        p[u] = v; d[u] = du;
        q.push({ d[u], u });
      }
    }

    if (d[t] == infty) throw runtime_error("no path");

    vector<int> path;
    int curr = t;
    while (curr != s)
    {
      path.push_back(curr);
      curr = p[curr];
    }
    path.push_back(s);
    reverse(path.begin(), path.end());

    vector<coord> ans;
    for (int i = 1; i < path.size() - 1; ++i)
    {
      if (color[path[i]] != -1) continue;
      ans.push_back(which[path[i]]);
    }
    return ans;
  }

  graph(vector<vector<int>> board)
  {
    int n = board.size();

    mat.assign(n * n + 4, vector<int>(n * n + 4));
    color.assign(n * n + 4, -1);
    which.assign(n * n + 4, { -1,-1 });

    // vertical player:
    s0 = n * n;   color[s0] = 0;
    t0 = n * n + 1; color[t0] = 0;
    // horizontal player:
    s1 = n * n + 2; color[s1] = 1;
    t1 = n * n + 3; color[t1] = 1;

    vector<coord> dirs = { {-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0} };
    auto is_inside = [&](coord c) { return (0 <= c.x && c.x < n) && (0 <= c.y && c.y < n); };
    auto idx = [&](coord c) { return c.x * n + c.y; };

    for (int i = 0; i < n; ++i)
    {
      add_edge(s0, idx({ 0, i }));
      add_edge(t0, idx({ n - 1, i }));
      add_edge(s1, idx({ i, 0 }));
      add_edge(t1, idx({ i, n - 1 }));
    }

    coord c;
    for (c.x = 0; c.x < n; ++c.x)
    for (c.y = 0; c.y < n; ++c.y)
    {
      color[idx(c)] = board[c.x][c.y];
      which[idx(c)] = c;
      for (auto& dir : dirs)
      {
          auto cd = c + dir;
          if (!is_inside(cd)) continue;
          add_edge(idx(c), idx(cd));
      }
    }
  }
};

struct base_bot : public player
{
  using player::player;
  virtual command move(const vector<vector<int>>& board)
  {
    auto g = graph(board);
    auto player = g.shortest_path(0);
    auto enemy = g.shortest_path(1);
    if (turn) swap(player, enemy);
    if (player.empty() || enemy.empty())  throw runtime_error("no available moves");

    coord ans;
    if (player.size() < enemy.size()) ans = player[player.size() / 2];
    else ans = enemy[enemy.size() / 2];

    return ans;
  }
  virtual void opponent_move(const vector<vector<int>>& board, const coord& c)
  {
    // yolo
  }
};

struct your_bot : public player
{
  using player::player;
  virtual command move(const vector<vector<int>>& board)
  {
    throw runtime_error("not implemented");
  }
  virtual void opponent_move(const vector<vector<int>>& board, const coord& c)
  {
    // if you need this
  }
};

player* pick_type(int turn)
{
  string name = turn ? "Horizontal (o)" : "Vertical (x)";
  cout << "Pick a type for " << name << " player:" << endl;
  cout << "(0) Human" << endl;
  cout << "(1) Base bot" << endl;
  cout << "(2) Your bot (to be implemented)" << endl;

  int t;
  cout << "Pick: "; cin >> t;
  if (t == 0) return new human(turn);
  if (t == 1) return new base_bot(turn);
  if (t == 2) return new your_bot(turn);
  throw invalid_argument("Invalid type selected");
}

int main()
{
  int n; cout << "Board size: "; cin >> n; reset(cin);
  player* p0 = pick_type(0);
  player* p1 = pick_type(1);
  hex_game hex(n, *p0, *p1);

  hex.run();

  delete p0;
  delete p1;
  return 0;
}
