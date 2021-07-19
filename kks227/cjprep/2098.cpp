#include "bits/stdc++.h"
using namespace std;

using pii = pair<int, int>;

static constexpr int kNone = -1;
static constexpr int kMax = INT_MAX / 2;

int DP(vector<vector<int>>& dp, const vector<vector<pii>>& graph, const int n, const int visited, const int start) {
    const int N = graph.size();
    if (visited == (1 << N) - 1) {
        return (n == start ? 0 : kMax);
    }
    auto& cur = dp[n][visited];
    if (cur != kNone) {
        return cur;
    }
    cur = kMax;
    for (const auto [nbd, dist] : graph[n]) {
        if ((visited & (1 << nbd)) == 0) {
            cur = min(cur, DP(dp, graph, nbd, visited | (1 << nbd), start) + dist);
        }
    }
    return cur;
}

int main()
{
    int N;
    cin >> N;
    vector<vector<pii>> graph(N);   // first: nbd, second: dist
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int d;
            cin >> d;
            if (d != 0) {
                graph[i].emplace_back(j, d);
            }
        }
    }

    vector<vector<int>> dp(N, vector<int>(1 << N, kNone));
    cout << DP(dp, graph, 0, 0, 0) << endl;

    return 0;
}


/*

dp[cur][visited] : cost to finish traversal w/ cur visited.
dp[cur][visited] = min(dp[nbd][nextvisited])

halt condition:
  visited == full -> 0

dp[0][0]
dp[1][0]
...
-> only need to do dp[0][0]
why? result of dp[1][0] -> 1 -> ... -> 1 => rotate => 0 -> ... -> 0.




*/
