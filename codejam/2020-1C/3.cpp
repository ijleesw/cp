#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

ll gcd(ll a, ll b) {
    if (a < b) swap(a, b);
    while (b > 0) {
        a %= b;
        swap(a, b);
    }
    return a;
}

ll solve() {
    ll N, D; cin >> N >> D;
    vector<ll> degs(N);
    for (int i = 0; i < N; ++i) cin >> degs[i];
    sort(begin(degs), end(degs));

    unordered_map<ll, pll> precom[51];      // first: fu count, second: piece count

    double l = 0, r = degs.back(), maxSize = -1;
    const double eps = 1e-4;
    while (r - l > eps) {
        double m = (l + r) / 2;
        ll cnt = 0;
        for (const auto deg : degs) {
            cnt += (ll)((double)deg / m);
        }
        if (cnt >= D) {
            maxSize = m;
            l = m;
        } else {
            r = m;
        }
//        printf("l=%lf, r=%lf, m=%lf\n", l, r, m);
    }
    assert (maxSize != -1);
    maxSize += 1./50;

//    printf("maxSize=%lf\n", maxSize);

    for (const auto deg : degs) {
        for (int d = D; d >= 1; --d) {
            ll g = gcd(deg, d);
            ll gD = d / g;
            ll gCurDeg = deg / g;

            if ((double)gCurDeg > (double)gD * maxSize) break;

            // do precomputation
            auto it = precom[gD].find(gCurDeg);
            if (it == end(precom[gD])) {        // add new piece
                precom[gD][gCurDeg] = pll(1, d);

            } else {        // already exists
                if (it->second.second < D) {
                    ++it->second.first;
                    it->second.second += d;
                }
            }
        }
    }
    // precomputation done

    ll res = std::numeric_limits<ll>::max();

    for (int i = 1; i <= D; ++i) {
        if (!precom[i].empty()) {
            for (const auto p : precom[i]) {
                if (p.second.second <= D) {
                    res = min(res, D - p.second.first);
                } else {
                    res = min(res, D - p.second.first + 1);
                }
            }
        }
    }

    return res;
}

int main() {
    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        ll res = solve();
        printf("Case #%d: %lld\n", t, res);
    }
    return 0;
}
