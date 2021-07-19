#include "bits/stdc++.h"
using namespace std;

int main() {
    int n, s; cin >> n >> s;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];

    int cnt = 0;
    int pow2 = pow(2, n);
    for (int val = 1; val < pow2; ++val) {
        int tgt = val;
        int idx = 0;
        int sum = 0;

        while (tgt > 0) {
            if (tgt % 2 == 1) sum += v[idx];
            ++idx;
            tgt /= 2;
        }
        if (sum == s) ++cnt;
    }
    cout << cnt << endl;

    return 0;
}