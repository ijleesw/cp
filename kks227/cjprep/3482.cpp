#include "bits/stdc++.h"
using namespace std;
using pii = pair<int, int>;

// first : continuable
// second : non_continuable
pii DFS(vector<bool>& visited, const vector<vector<bool>>& free, const int x, const int y)
{
    const auto idx = x * free[0].size() + y;
    visited[idx] = true;

    int xdiffs[4] = {-1, 0, 1, 0};
    int ydiffs[4] = {0, -1, 0, 1};

    int noncont = 0;
    vector<int> conts;
    for (int i = 0; i < 4; ++i) {
        const auto new_x = x + xdiffs[i];
        const auto new_y = y + ydiffs[i];
        const auto new_idx = new_x * free[0].size() + new_y;

        if (0 <= new_x && new_x < free.size() && 0 <= new_y && new_y < free[0].size() &&
                !visited[new_idx] && free[new_x][new_y]) {
            auto [child_cont, child_noncont] = DFS(visited, free, new_x, new_y);
            noncont = max(noncont, max(child_cont + 1, child_noncont));
            conts.push_back(child_cont);
        }
    }

    if (conts.size() >= 2) {
        partial_sort(begin(conts), begin(conts) + 2, end(conts), greater<int>());
        noncont = max(noncont, conts[0] + conts[1] + 2);
    }

    if (conts.empty()) {
        return {0, 0};
    } else {
        return {*max_element(begin(conts), end(conts)) + 1, noncont};
    }
}

int main()
{
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<vector<bool>> free(M, vector<bool>(N, false));
        int x = 0, y = 0;
        for (int i = 0; i < M; ++i) {
            string line;
            cin >> line;
            for (int j = 0; j < N; ++j) {
                if (line[j] == '.') {
                    free[i][j] = true;
                    x = i;
                    y = j;
                }
            }
        }
        // end of input
        vector<bool> visited(M * N, false);
        const auto res = DFS(visited, free, x, y);
        cout << "Maximum rope length is " << max(res.first, res.second) << ".\n";
    }

    return EXIT_SUCCESS;
}