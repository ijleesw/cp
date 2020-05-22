#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
    int k, n; cin >> k >> n;
    vector<ll> len(k);
    for (int i = 0; i < k; ++i) cin >> len[i];

    ll l = 1;
    ll r = *max_element(begin(len), end(len));
    ll res = -1;

    while (l <= r) {
        ll m = (l+r) / 2;
        int cnt = 0;
        for (const auto l : len) {
            cnt += l / m;
        }
        if (cnt < n) {
            r = m-1;
        } else {
            res = m;
            l = m+1;
        }
    }

    assert(res != -1);
    cout << res << endl;
    return 0;
}