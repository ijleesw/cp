#include "bits/stdc++.h"
using namespace std;

static constexpr int kUnvisited = -1;
static constexpr int kInvalid = numeric_limits<int>::max() / 2;

int DP(vector<int>& cost, const vector<vector<int>>& graph, const int fixed, const int remaining)
{
    const int N = graph.size();
    auto& cur_cost = cost[fixed];

    if (remaining <= 0 || fixed == (1 << N) - 1) {
        return cur_cost = 0;
    }
    if (cur_cost != kUnvisited) {
        return cur_cost;
    }
    cur_cost = kInvalid;

    for (int i = 0; i < N; ++i) {
        if (!(fixed & (1 << i))) {
            continue;
        }
        for (int j = 0; j < N; ++j) {
            if (fixed & (1 << j)) {
                continue;
            }
            // now i fixed & j not fixed
            const int wt = graph[i][j];
            cur_cost = min(cur_cost, wt + DP(cost, graph, fixed | (1 << j), remaining - 1));
        }
    }

    return cur_cost;
}

int main()
{
    int N;
    cin >> N;
    vector<vector<int>> graph(N, vector<int>(N));
    for (auto& row : graph) {
        for (auto& elt : row) {
            cin >> elt;
        }
    }
    int fixed = 0;
    int remaining = 0;
    for (int i = 0; i < N; ++i) {
        char c;
        cin >> c;
        if (c == 'Y') {
            fixed |= (1 << i);
            --remaining;
        }
    }
    int P;
    cin >> P;
    remaining += P;
    // end of input

    vector<int> cost((1 << N), kUnvisited);
    const auto res = DP(cost, graph, fixed, remaining);
    cout << (res == kInvalid ? -1 : res) << endl;

    return EXIT_SUCCESS;
}