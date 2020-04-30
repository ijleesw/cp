#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

ll daq(const vector<ll>& v, int l, int r) {  // r: inclusive
    if (l == r) return v[l] * v[l];

    ll left = daq(v, l, (l+r)/2);
    ll right = daq(v, (l+r)/2+1, r);
    ll center = 0;

    int i = (l+r)/2, j = i+1;
    ll cur_sum = v[i] + v[j];
    ll cur_min = min(v[i], v[j]);

    while (true) {
        center = max(center, cur_sum * cur_min);
        if (i == l && j == r) break;

        if (i == l || (l < i && j < r && v[i-1] < v[j+1])) {
            ++j;
            cur_sum += v[j];
            cur_min = min(cur_min, v[j]);
        } else /* if (j == r || (l < i && j < r && v[i-1] <= v[j+1])) */ {
            --i;
            cur_sum += v[i];
            cur_min = min(cur_min, v[i]);
        }
    }

    return max(max(left, right), center);
}

int main() {
    int n; cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];

    cout << daq(v, 0, n-1) << endl;

    return 0;
}