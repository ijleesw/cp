#include "bits/stdc++.h"
using namespace std;
using pii = pair<int, int>;

int main()
{
    int N;
    cin >> N;

    vector<pii> pairs;
    pairs.reserve(N);
    while (N--) {
        int n;
        cin >> n;
        int cur_max = 0;
        for (const auto& p : pairs) {
            if (p.first < n) {
                cur_max = max(cur_max, p.second);
            }
        }
        pairs.emplace_back(n, cur_max + n);
    }

    int max_val = 0;
    for (const auto& p : pairs) {
        max_val = max(max_val, p.second);
    }
    cout << max_val << endl;

    return 0;
}