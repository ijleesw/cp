#include "bits/stdc++.h"
using namespace std;

int daq(const vector<int>& v, int l, int r) {   // r: inclusive
    if (l == r) return v[l];

    int res = max(daq(v, l, (l+r)/2), daq(v, (l+r)/2+1, r));

    int i = (l+r)/2, j = i+1;
    int min_h = min(v[i], v[j]);

    while (true) {
        res = max(res, min_h * (j-i+1));
        if (l == i && j == r) break;

        if (l == i || (l < i && j < r && v[i-1] < v[j+1])) {
            ++j;
            min_h = min(min_h, v[j]);
        }
        else {
            --i;
            min_h = min(min_h, v[i]);
        }
    }

    return res;
}

int main() {
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];

    cout << daq(v, 0, n-1) << endl;
    return 0;
}