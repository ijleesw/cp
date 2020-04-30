#include "bits/stdc++.h"
using namespace std;
using pii = pair<int, int>;

int main() {
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    v.push_back(0);

    int max_val = 0;
    stack<pii> s;

    for (int i = 0; i <= n; ++i) {
        int last_pop = i;
        while (!s.empty() && s.top().second > v[i]) {
            max_val = max(max_val, s.top().second * (i - s.top().first));
            last_pop = s.top().first;
            s.pop();
        }
        s.emplace(last_pop, v[i]);
    }

    cout << max_val << endl;
    return 0;
}
