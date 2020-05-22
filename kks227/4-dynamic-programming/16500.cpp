#include "bits/stdc++.h"
using namespace std;

bool isSubstr(const string& base, const string& cand, int start) {
    if (start + cand.length() > base.length()) return false;
    for (int i = 0; i < cand.length(); ++i) {
        if (base[i+start] != cand[i]) return false;
    }
    return true;
}

int main() {
    string s; cin >> s;
    int n; cin >> n;
    vector<string> cands(n);
    for (int i = 0; i < n; ++i) cin >> cands[i];

    set<int> startpoints;
    startpoints.insert(0);

    bool possible = false;
    while (!startpoints.empty()) {
        int start = *begin(startpoints);
        startpoints.erase(start);
//        printf("cur start : %d\n", start);

        if (start == s.length()) {
            possible = true;
            break;
        }

        for (const auto& cand : cands) {
            if (isSubstr(s, cand, start)) startpoints.insert(start + cand.length());
        }
    }

    cout << (int)possible << endl;

    return 0;
}
