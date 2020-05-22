#include "bits/stdc++.h"
using namespace std;
using pii = pair<int, int>;

int main() {
    int T; cin >> T;
    for (int t = 0; t < T; ++t)
    {
        int n, m; cin >> n >> m;
        deque<pii> dq;
        for (int i = 0; i < n; ++i) {
            int e; cin >> e; dq.push_back(pii(e, i));
        }

        int cnt = 0;

        while (true) {
            int head = dq.front().first;
            int idx = dq.front().second;
            bool is_highest = true;

            for (int i = 1; i < dq.size(); ++i) {
                if (dq[i].first > head) {
                    is_highest = false;
                    break;
                }
            }

            if (is_highest) {
                ++cnt;
                dq.pop_front();
                if (m == idx) break;

            } else {
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }

        std::cout << cnt << std::endl;
    }

    return 0;
}