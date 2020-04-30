#include "bits/stdc++.h"
using namespace std;

using pii = pair<int, int>;

bool PiiCmp(const pii& lhs, const pii& rhs) {
    return lhs.first < rhs.first;
}

int main() {
    vector<pii> pbs;
    for (int i = 0; i < 11; ++i) {
        int a, b; cin >> a >> b;
        pbs.emplace_back(a, b);
    }
    sort(begin(pbs), end(pbs), PiiCmp);

    int total = 0;
    int t = 0;
    for (auto pb : pbs) {
        t += pb.first;
        total += t + pb.second*20;
    }
    cout << total << endl;

    return 0;
}