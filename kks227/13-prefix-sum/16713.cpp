#include "bits/stdc++.h"
using namespace std;

int main()
{
    int n, q; cin >> n>> q;
    vector<int> xs{0};
    while (n--) {
        int x; scanf("%d", &x);
        xs.push_back(xs.back() ^ x);
    }
    int res = 0;
    while (q--) {
        int a, b; scanf("%d %d", &a, &b);
        res ^= (xs[b] ^ xs[a - 1]);
    }
    cout << res << endl;
    return 0;
}