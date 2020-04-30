#include "bits/stdc++.h"
using namespace std;
using pii = pair<int, int>;
using ll = long long;

int main() {
    int l, n, rf, rb; cin >> l >> n >> rf >> rb;
    vector<pii> xcs(n);
    for (int i = 0; i < n; ++i) cin >> xcs[i].first >> xcs[i].second;
    sort(begin(xcs), end(xcs),
         [](const pii& lhs, const pii& rhs) { return lhs.second > rhs.second; });

    int last_meet = 0;
    ll total = 0;
    for (auto xc : xcs) {
        int x = xc.first, c = xc.second;
        if (x <= last_meet) continue;

        total += (ll)c * (x - last_meet) * (rf - rb);
        last_meet = x;
    }

    cout << total << endl;
    return 0;
}