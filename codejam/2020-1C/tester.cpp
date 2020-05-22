#include "bits/stdc++.h"
using namespace std;
using ll = unsigned long long;

typedef unsigned long long int UINT64;

UINT64 getRandom(UINT64 const& min = 0, UINT64 const& max = 0)
{
    return (((UINT64)(unsigned int)rand() << 32) + (UINT64)(unsigned int)rand()) % (max - min) + min;
}

int main() {
    srand(time(0));
    int e = 16;
    cout << 1 << endl;
    cout << e << endl;

    ll upper = pow(10, e) - 1;
    ll cnt[10] = {};

    for (int i = 0; i < 10000; ++i) {
        ll up = getRandom(1, upper);
        string num = to_string(getRandom(1, up));
        cout << -1 << ' ' << num << endl;
        ++cnt[num[0] - '0'];

    }

    for (int i = 0; i < 10; ++i) cout << cnt[i] << ' ';
    cout << endl;

    return 0;

}