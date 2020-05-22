#include "bits/stdc++.h"
using namespace std;
using ll = long long;

struct Room {
    ll t, a, h;
//    Room(ll t0, ll a0, ll h0) : t(t0), a(a0), h(h0) {}
};

int main() {
    ll N, A; cin >> N >> A;
    vector<Room> rs(N);
    for (int i = 0; i < N; ++i) cin >> rs[i].t >> rs[i].a >> rs[i].h;
    // end of input

    ll l = 1;
    ll r = numeric_limits<ll>::max() - l;
    ll res = -1;

    while (l <= r) {
        const auto m = (l + r) / 2;
        auto cur_h = m;
        auto cur_a = A;
        bool able = true;

        for (const auto& r : rs) {
            if (r.t == 1) {
                ll n_atk = (r.h + cur_a - 1) / cur_a;
                cur_h -= (n_atk - 1) * r.a;
                if (cur_h <= 0) {
                    able = false;
                    break;
                }
            } else {
                cur_h = min(m, cur_h + r.h);
                cur_a += r.a;
            }
        }

        if (able) {
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