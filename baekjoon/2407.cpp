// XXX: WA!
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
    int n, m; cin >> n >> m;
    if (n < 2*m) m = n-m;

    ll res = 1;
    int under = 1;
    for (int i = n; i >= n-m+1; --i) {
        res *= i;
        while (under <= m) {
            if (res % under == 0) res /= under, ++under;
            else break;
        }
    }

    cout << res << endl;
    return 0;
}