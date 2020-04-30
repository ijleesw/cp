#include "bits/stdc++.h"
using namespace std;

int main() {
    for (int t = 1; ; ++t) {
        int L, P, V; cin >> L >> P >> V;
        if (L == 0 && P == 0 && V == 0) break;

        int res = 0;
        while (V > 0) {
            res += min(L, V);
            V -= min(P, V);
        }
        printf("Case %d: %d\n", t, res);
    }

    return 0;
}