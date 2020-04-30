#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
    ll l, w, h; cin >> l >> w >> h;
    ll vol = l*w*h;

    vector<ll> cnt(20, 0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        int k; cin >> k;
        cin >> cnt[k];
    }
    // end of input

    int cube_cnt = 0;
    ll rem_vol_to_fill = 0;
    for (int i = cnt.size()-1; i >= 0; --i) {
        ll cur_side = pow(2, i);
        ll cur_vol = pow(cur_side, 3);

        if (rem_vol_to_fill > 0) {
            // TODO: do something
        }

        int cnt_l = l / cur_side;
        int cnt_w = w / cur_side;
        int cnt_h = h / cur_side;
    }

    if (vol == 0) cout << cube_cnt << endl;
    else cout << -1 << endl;

    return 0;
}