#include "bits/stdc++.h"
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> to(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> to[i];
    }

    // 0 : not
    // 1 : visited
    // 2 : processed
    vector<int> visited(N + 1, 0);

    int grp_idx = 10000;
    unordered_map<int, int> grp_rem;
    unordered_map<int, int> grp_cycle;

    for (int i = 1; i <= N; ++i) {
        // iterate until cycle is found
        auto cur = i;
        while (!visited[cur]) {
            visited[cur] = 1;
            cur = to[cur];
        }

        // already processed -> continue
        if (visited[cur] != 1) {
            const auto grp = visited[cur];
            cur = i;
            while (visited[cur] == 1) {
                visited[cur] = grp;
                ++grp_rem[grp];
            }
            continue;
        }
        // now new group
        ++grp_idx;

        // get cycle size
        int sz = 0;
        while (visited[cur] == 1) {
            visited[cur] = grp_idx;
            ++sz;
            cur = to[cur];
        }
        grp_cycle[grp_idx] = sz;

        // process remaining nodes
        cur = i;
        while (visited[cur] == 1) {
            visited[cur] = grp_idx;
            ++grp_rem[grp_idx];
            cur = to[cur];
        }
    }

    vector<pair<int, int>> vp;
    for (const auto& p : grp_cycle) {
        vp.emplace_back(p.second, grp_rem[p.first]);
    }

    vector<bool> dp(K + 1, false);
    dp[0] = true;
    for (const auto& p : vp) {
        for (int i = K ; i >= p.first; --i) {
            for (int j = min(K , i + p.second); j >= i; --j) {
                dp[j] = dp[j] || dp[i - p.first];
            }
        }
    }

    for (int i = K; i >= 0; --i) {
        if (dp[i]) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}