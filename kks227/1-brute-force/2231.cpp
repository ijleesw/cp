#include "bits/stdc++.h"
using namespace std;

bool IsGen(int src, int tgt) {
    int sum = src;
    while (src > 0) {
        sum += src % 10;
        src /= 10;
    }
    return sum == tgt;
}

int main() {
    int n; cin >> n;

    for (int i = 0; i <= n; ++i) {
        if (IsGen(i, n)) {
            cout << i << endl;
            return 0;
        }
    }

    cout << 0 << endl;
    return 0;
}