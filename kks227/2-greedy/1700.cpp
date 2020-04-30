#include "bits/stdc++.h"
using namespace std;

int main() {
    int n, k; cin >> n >> k;
    vector<int> v(k);
    for (int i = 0; i < k; ++i) cin >> v[i];

    int cur = 0;
    unordered_set<int> us;

    int cnt = 0;
    for (int i = 0; i < k; ++i) {
        if (us.size() < n || us.find(v[i]) != end(us)) {
            us.insert(v[i]);
            continue;
        }
        // now us is full and new elt ready to insert.

        unordered_set<int> tmp_us = us;
        for (int j = i+1; j < k && tmp_us.size() > 1; ++j) {
            tmp_us.erase(v[j]);
        }

        us.erase(*tmp_us.begin());
        us.insert(v[i]);
        ++cnt;
    }

    cout << cnt << endl;
    return 0;
}