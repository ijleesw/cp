#include "bits/stdc++.h"
using namespace std;

int main() {
    const int kMax = INT_MAX/2;
    int n; cin >> n;
    vector<int> cnt(n+1, kMax); cnt[n] = 0;
    for (int i = n; i >= 1; --i) {
        if (cnt[i] == kMax) continue;
        if (i-1 > 0) cnt[i-1] = min(cnt[i-1], cnt[i]+1);
        if (i % 2 == 0 && i/2 > 0) cnt[i/2] = min(cnt[i/2], cnt[i]+1);
        if (i % 3 == 0 && i/3 > 0) cnt[i/3] = min(cnt[i/3], cnt[i]+1);
    }
    cout << cnt[1] << endl;
    return 0;
}