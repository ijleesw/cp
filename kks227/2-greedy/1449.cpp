#include "bits/stdc++.h"
using namespace std;

int main() {
    int n, l; cin >> n >> l;

    int cnt = 0;
    double cur_end = -1;

    vector<int> pv(n);
    while (n--)  cin >> pv[n];
    sort(begin(pv), end(pv));

    for (auto p : pv) {
        if (cur_end < (double)p + 0.5) {
            cur_end = (double)p + l - 0.5;
            ++cnt;
        }
    }

    cout << cnt << endl;
    return 0;
}