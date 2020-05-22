#include "bits/stdc++.h"
using namespace std;

struct S {
    int from, to, dist;
};

int main() {
    int N, K, D; cin >> N >> K >> D;
    vector<S> ss(K);
    for (int i = 0; i < K; ++i) cin >> ss[i].from >> ss[i].to >> ss[i].dist;

    int l = 1;
    int r = 1000000;
    int res = -1;

    while (l <= r) {
        const int m = (l + r) / 2;
        int rem = D;
        // m : current position

        for (const auto& s : ss) {
            if (m >= s.from) {
                rem -= (min(s.to, m) - s.from + s.dist) / s.dist;
            }
            if (rem <= 0) break;
        }

        if (rem <= 0) {
            res = m;
            r = m-1;
        } else {
            l = m+1;
        }
    }

    assert(res != -1);
    cout << res << endl;
    return 0;
}