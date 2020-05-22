#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
    ll N, K; cin >> N >> K;
    // x보다 leq인 수가 K개이면 ok

    ll l = 1;
    ll r = N*N;
    ll res = -1;

    while (l <= r) {
        const auto m = (l + r) / 2;
        ll cnt = 0;

        for (ll i = 1; i <= N; ++i) {
            cnt += min(m / i, N);
            if (cnt >= K) break;
        }

        if (cnt >= K) {
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