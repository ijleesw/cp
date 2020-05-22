#include "bits/stdc++.h"
using namespace std;
using pii = pair<int, int>;

int main() {
    int n, k; cin >> n >> k;
    vector<pii> pv(n);
    for (int i = 0; i < n; ++i) {
        cin >> pv[i].first >> pv[i].second;
    }

    vector<int> val(k+1, 0);
    for (const auto p : pv) {
        for (int i = k; i >= p.first; --i) {
            val[i] = max(val[i], val[i-p.first]+p.second);
        }
    }

    cout << *max_element(begin(val), end(val)) << endl;

    return 0;
}