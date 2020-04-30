#include "bits/stdc++.h"
using namespace std;
using pii = pair<int, int>;

bool PiiCmp(const pii& lhs, const pii& rhs) {
    return lhs.second > rhs.second;
}

int main() {
    int n; cin >> n;
    vector<pii> hws(n);
    for (int i = 0; i < n; ++i) cin >> hws[i].first >> hws[i].second;
    sort(begin(hws), end(hws), PiiCmp);

    int sum = 0;
    vector<bool> valid(1001, true);
    for (auto hw : hws) {
        for (int i = hw.first; i >= 1; --i) {
            if (valid[i]) {
                valid[i] = false;
                sum += hw.second;
                break;
            }
        }
    }
    cout << sum << endl;

    return 0;
}