#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int solve() {
    int u; cin >> u;
    unordered_map<char, int> um;
    unordered_set<char> nonzero;
    unordered_set<char> all;

    for (int i = 0; i < 10000; ++i) {
        ll num; string line;
        cin >> num >> line;
        for (auto c : line) all.insert(c);
        ++um[line[0]];
        nonzero.insert(line[0]);
    }

    using pic = pair<int, char>;
    vector<pic> vp;

    for (auto it = begin(all); it != end(all); ++it) {
        if (nonzero.find(*it) == end(nonzero)) {
            printf("%c", *it);
            break;
        }
    }

    for (auto it = begin(um); it != end(um); ++it) {
        vp.emplace_back(it->second, it->first);
    }
    sort(begin(vp), end(vp), [](const pic& lhs, const pic& rhs) { return lhs.first > rhs.first; });

    for (int i = 0; i < 9; ++i) printf("%c", vp[i].second);
    printf("\n");

    return 0;
}

int main() {
    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        printf("Case #%d: ", t);
        solve();
    }
    return 0;
}
