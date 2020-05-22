#include "bits/stdc++.h"
using namespace std;
using pii = pair<int, int>;

int main()
{
    int N, K; cin >> N >> K;
    vector<int> to(N);
    for (int i = 0; i < N; ++i) {
        int a; cin >> a; to[i] = --a;
    }
    // end of input

    vector<int> status(N, -1);
    vector<int> cycle_idx(N, -1);
    unordered_map<int, pii> cpnts;      // min idx -> (size, incl. additional)

    for (int i = 0; i < N; ++i) {
        int cur = i;
        int total = 0;
        int cycle = 0;
        int min_idx = INT_MAX;

        while (true) {
            if (status[cur] == -1) {
                ++total;
                status[cur] = i;
                cur = to[cur];

            } else if (status[cur] == i) {
                // cycle detected.
                int cyc = cur;
                while (true) {
                    min_idx = min(min_idx, cyc);
                    ++cycle;
                    cyc = to[cyc];
                    if (cyc == cur) break;
                }

//                printf("cur=%d, min_idx=%d, cycle=%d, total=%d\n", cur, min_idx, cycle, total);

                cycle_idx[i] = min_idx;
                cpnts[min_idx] = pii(cycle, total);
                break;

            } else {
                // should augment to cycle
                cpnts[cycle_idx[cur]].second += total;
                min_idx = cycle_idx[cur];
                break;
            }
        }

        cur = i;
        while (total--) {
            cycle_idx[cur] = min_idx;
            cur = to[cur];
        }
    }

//    for (const auto& cpnt : cpnts) {
//        printf("cycle head idx : %d, size : %d, total : %d\n", cpnt.first, cpnt.second.first, cpnt.second.second);
//    }

    vector<bool> dp(K+1); dp[0] = true;
    for (const auto& cpnt : cpnts) {
        for (int i = K; i >= 0; --i) {
            if (dp[i]) {
                for (int j = cpnt.second.first; j <= cpnt.second.second; ++j) {
                    if (i + j > K) break;
                    dp[i+j] = true;
                }
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