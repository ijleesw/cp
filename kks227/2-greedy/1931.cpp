#include "bits/stdc++.h"
using namespace std;
using pii = pair<int, int>;

bool PiiCmp(const pii& lhs, const pii& rhs) {
    return lhs.second < rhs.second || (lhs.second == rhs.second && lhs.first < rhs.first);
}

int main() {
    int n; cin >> n;
    vector<pii> tt(n);
    for (int i = 0; i < n; ++i) cin >> tt[i].first >> tt[i].second;
    sort(begin(tt), end(tt), PiiCmp);

    int cur_end = -1;
    int cnt = 0;
    for (auto t : tt) {
        if (cur_end <= t.first) {
            cur_end = t.second;
            ++cnt;
        }
    }

    cout << cnt << endl;
    return 0;
}