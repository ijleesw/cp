#include "bits/stdc++.h"
using namespace std;

int main() {
    int n, k; cin >> n >> k;
    vector<int> ss(n);
    for (int i = 0; i < n; ++i) cin >> ss[i];
    sort(begin(ss), end(ss));

    if (n <= k) {
        cout << 0 << endl;
        return 0;
    }

    vector<int> diff(n-1);
    for (int i = 0; i < n-1; ++i) diff.push_back(ss[i+1] - ss[i]);
    sort(begin(diff), end(diff));

    int sum = 0;
    for (int i = 0; i < diff.size() - (k - 1); ++i) sum += diff[i];
    cout << sum << endl;

    return 0;
}
