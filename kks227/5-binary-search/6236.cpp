#include "bits/stdc++.h"
using namespace std;

int main() {
    int N, M; cin >> N >> M;
    vector<int> money(N);
    for (int i = 0; i < N; ++i) cin >> money[i];
    // end of input.

    int l = *max_element(begin(money), end(money));
    int r = accumulate(begin(money), end(money), 0);
    int res = -1;

    while (l <= r) {
        const int m = (l + r) / 2;
        int cur = 0;
        int get = 0;

        for (const auto mon : money) {
            if (mon > cur) {
                cur = ((mon + m - 1) / m) * m;
                get += (mon + m - 1) / m;
            }
            // now mon <= cur
            cur -= mon;
        }

//        printf("m=%d, get=%d\n", m, get);

        if (get <= M) {
            res = m;
            r = m-1;
        } else {
            l = m+1;
        }
    }

    assert(res != -1);
    cout << res << endl;
    return 0;
}