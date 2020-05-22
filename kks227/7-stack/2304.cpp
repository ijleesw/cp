#include "bits/stdc++.h"
using namespace std;
using pii = pair<int, int>;

int main() {
    int N; cin >> N;
    vector<pii> hs(N);
    for (int i = 0; i < N; ++i) cin >> hs[i].first >> hs[i].second;
    // end of input

    sort(begin(hs), end(hs));

    int l = 0;
    int r = hs.size() - 1;
    int lh = hs[0].second;
    int rh = hs[r].second;
    int area = 0;

    while (l < r) {
//        printf("prev: l=%d, lh=%d, r=%d, rh=%d, area=%d\n", l, lh, r, rh, area);
        if (lh <= rh) {
            int diff = hs[l+1].first - hs[l].first;
            area += diff * lh;
            lh = max(lh, hs[l+1].second);
            ++l;
        } else {
            int diff = hs[r].first - hs[r-1].first;
            area += diff * rh;
            rh = max(rh, hs[r-1].second);
            --r;
        }
//        printf("done: l=%d, lh=%d, r=%d, rh=%d, area=%d\n\n", l, lh, r, rh, area);
    }

    area += hs[l].second;

    cout << area << endl;
    return 0;
}