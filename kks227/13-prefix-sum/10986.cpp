#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    int n, M; cin >> n >> M;
    vector<int> sum(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        int x; scanf("%d", &x);
        sum[i + 1] = (sum[i] + x) % M;
    }

    unordered_map<int, int> rem_map;
    for (auto s : sum) {
        ++rem_map[s];
    }

    ll cnt = 0;
    for (const auto& p : rem_map) {
        cnt += ll(p.second) * (p.second - 1) / 2;
    }
    std::cout << cnt << "\n";
    return 0;
}
