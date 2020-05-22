#include "bits/stdc++.h"
using namespace std;

int main() {
    vector<int> frets[7];
    int cnt = 0;

    int N, F; cin >> N >> F;
    for (int i = 0; i < N; ++i) {
        int f, n; cin >> f >> n;
        auto& fret = frets[f];

        auto it = lower_bound(begin(fret), end(fret), n);
        if (it == end(fret)) {   // highest
            ++cnt;
            fret.push_back(n);
        } else if (*it == n) {   // not highest & exists
            cnt += end(fret) - it - 1;
            fret.erase(it+1, end(fret));
        } else {                 // not highest & not exists
            cnt += end(fret) - it + 1;
            fret.erase(it, end(fret));
            fret.push_back(n);
        }
    }

    cout << cnt << endl;
    return 0;
}