#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pis = pair<int, string>;

int main() {
    int n, k; cin >> n >> k;

    unordered_map<int, vector<pis>> um;

    for (int i = 0; i < n; ++i) {
        string name; cin >> name;
        um[name.size()].push_back(pis(i, std::move(name)));
    }

    ll cnt = 0;

    for (auto it = begin(um); it != end(um); ++it) {
        auto& vec = it->second;
        int l = 0;
        int r = 0;
        while (l < vec.size()) {
            while (r < vec.size() && vec[r].first - vec[l].first <= k) ++r;  // r: exclusive
            cnt += (r - l - 1);
            ++l;
        }
    }

    std::cout << cnt << std::endl;


    return 0;
}