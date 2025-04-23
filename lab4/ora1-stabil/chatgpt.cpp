#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <limits>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    // Read boys' preferences.
    // boys[i] holds the preference list of boy (i+1)
    vector<vector<int>> boys(n);
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        boys[i].resize(k);
        for (int j = 0; j < k; j++) {
            cin >> boys[i][j];
        }
    }

    // Read girls' preferences and create a ranking for each girl.
    // For each girl, the lower the rank value, the more preferred the boy.
    // We use an unordered_map to map boy id (1-indexed) to its rank.
    vector<unordered_map<int, int>> girls(m);
    for (int j = 0; j < m; j++) {
        int k;
        cin >> k;
        for (int pos = 0; pos < k; pos++) {
            int boy;
            cin >> boy;
            girls[j][boy] = pos;
        }
    }

    // Initialize matchings:
    // matchBoy[i] stores the girl (1-indexed) matched with boy (i+1), or -1 if unmatched.
    // matchGirl[j] stores the boy (0-indexed) matched with girl (j+1), or -1 if unmatched.
    vector<int> matchBoy(n, -1);
    vector<int> matchGirl(m, -1);

    // nextProposal[i] holds the index of the next girl in boy i's list to whom he has not yet proposed.
    vector<int> nextProposal(n, 0);

    // All boys start free.
    queue<int> freeBoys;
    for (int i = 0; i < n; i++) {
        freeBoys.push(i);
    }

    // Gale-Shapley algorithm: While there is a free boy with someone left to propose.
    while (!freeBoys.empty()) {
        int boy = freeBoys.front();
        freeBoys.pop();

        // If this boy has proposed to everyone on his list, skip him.
        if (nextProposal[boy] >= boys[boy].size()) {
            continue;
        }

        // Get the next girl from his preference list.
        int girl = boys[boy][nextProposal[boy]];
        nextProposal[boy]++;
        int girlIndex = girl - 1;  // converting to 0-indexed

        // If the girl is free, engage her with the boy.
        if (matchGirl[girlIndex] == -1) {
            matchGirl[girlIndex] = boy;
            matchBoy[boy] = girl;
        } else {
            // Girl is currently matched; check her preferences.
            int currentBoy = matchGirl[girlIndex];
            // Get ranking for new proposal (boy+1) and current partner (currentBoy+1)
            int newRank = girls[girlIndex].count(boy + 1) ? girls[girlIndex][boy + 1] : numeric_limits<int>::max();
            int currentRank = girls[girlIndex].count(currentBoy + 1) ? girls[girlIndex][currentBoy + 1] : numeric_limits<int>::max();

            // If she prefers the new proposal, she switches.
            if (newRank < currentRank) {
                matchGirl[girlIndex] = boy;
                matchBoy[boy] = girl;
                matchBoy[currentBoy] = -1;
                // The dumped boy becomes free.
                freeBoys.push(currentBoy);
            } else {
                // Otherwise, she rejects the proposal; boy remains free if he has more to try.
                freeBoys.push(boy);
            }
        }
    }

    // Prepare and output the result.
    // Only output pairs for boys who ended up matched.
    vector<pair<int, int>> matching;
    for (int i = 0; i < n; i++) {
        if (matchBoy[i] != -1) {
            // Output is 1-indexed for both boys and girls.
            matching.push_back({i + 1, matchBoy[i]});
        }
    }

    cout << matching.size() << "\n";
    for (auto &pair : matching) {
        cout << pair.first << " " << pair.second << "\n";
    }

    return 0;
}
