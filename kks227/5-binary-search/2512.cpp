#include "bits/stdc++.h"
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> money(N);
    for (int i = 0; i < N; ++i) cin >> money[i];
    int M; cin >> M;
    // end of input.

    sort(begin(money), end(money));
    vector<int> presum(money);
    for (int i = 1; i < presum.size(); ++i) presum[i] += presum[i-1];

    int l = 1;
    int r = money.back();
    int res = -1;
    while (l <= r) {
        int m = (l + r) / 2;
        int cur_sum = 0;

        auto it = lower_bound(begin(money), end(money), m);
        auto d = it - begin(money);
        if (d == 0) cur_sum = 0;
        else cur_sum = presum[d - 1];
        cur_sum += m * (N - d);

        if (cur_sum <= M) {
            res = m;
            l = m+1;
        } else {
            r = m-1;
        }
    }

    assert(res != -1);
    cout << res << endl;

    return 0;
}