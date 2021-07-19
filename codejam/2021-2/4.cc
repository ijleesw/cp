#include "bits/stdc++.h"
using namespace std;

static constexpr int xd[4] = {-1, 1, 0, 0};
static constexpr int yd[4] = {0, 0, -1, 1};

struct State {
    string board;
    int cost;
    bool operator>(const State& rhs) const {
        return cost > rhs.cost;
    }
};

int solve() {
    int N, M, F, S;
    cin >> N >> M >> F >> S;

    string from;
    for (int i = 0; i < N; ++i) {
        string row;
        cin >> row;
        from.append(row);
    }
    string to;
    for (int i = 0; i < N; ++i) {
        string row;
        cin >> row;
        to.append(row);
    }

    priority_queue<State, vector<State>, greater<State>> min_pq;
    unordered_map<string, int> minCost;
    min_pq.push({from, 0});
    minCost[from] = 0;

    while (!min_pq.empty()) {
        auto [cur, cost] = min_pq.top();
        min_pq.pop();
        if (cur == to) {
            return cost;
        }

        int idx = 0;
        for (; idx < N * M; ++idx) {
            if (cur[idx] != to[idx]) {
                break;
            }
        }
        const int x = idx / M;
        const int y = idx % M;
        
        for (int i = 0; i < 4; ++i) {
            const auto nx = x + xd[i];
            const auto ny = y + yd[i];
            if (0 <= nx && nx < N && 0 <= ny && ny < M) {
                //if (cur[x * M + y] == to[nx * M + ny] && cur[nx * M + ny] == to[x * M + y]) {
                    swap(cur[x * M + y], cur[nx * M + ny]);
                    auto iter = minCost.find(cur);
                    if (iter == end(minCost) || cost + S < iter->second) {
                        min_pq.push({cur, cost + S});
                        minCost[cur] = cost + S;
                    }
                    swap(cur[x * M + y], cur[nx * M + ny]);
                //}
            }
        }
        cur[x * M + y] = to[x * M + y];
        auto iter = minCost.find(cur);
        if (iter == end(minCost) || cost + F < iter->second) {
            min_pq.push({cur, cost + F});
            minCost[cur] = cost + F;
        }
    }

    return -1;
}

int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cout << "Case #" << t << ": " << solve() << endl;
    }

    return 0;
}
