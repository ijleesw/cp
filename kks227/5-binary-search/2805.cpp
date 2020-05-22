#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
    int n, M; cin >> n >> M;
    vector<int> h(n);
    for (int i = 0; i < n; ++i) cin >> h[i];

    int l = 0;
    int r = *max_element(begin(h), end(h));
    int res = -1;
    while (l <= r) {
        int m = (l+r) / 2;
        ll sum = 0;
        for (auto e : h) {
            sum += max(0, (e - m));
        }
        if (sum < M) {
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