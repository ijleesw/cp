#include "bits/stdc++.h"
using namespace std;
using ll = long long;

ll recur(ll a, ll b, ll c) {
    if (b == 0) return 1;
    if (b == 1) return a % c;

    ll half = recur(a, b/2, c);
    ll res = (half * half) % c;
    if (b % 2 == 0) return res;
    else return (res * a) % c;
}

int main() {
    int a, b, c; cin >> a >> b >> c;
    cout << recur(a, b, c) << endl;
    return 0;
}