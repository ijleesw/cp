#include "bits/stdc++.h"
using namespace std;

int main() {
    int sum = 0, max_sum = INT_MIN;

    int n; cin >> n;
    for (int r = 0; r < n; ++r) {
        int cur; cin >> cur;

        if (r == 0 || sum + cur > 0) {
            sum += cur;
            max_sum = max(max_sum, sum);
        }
        else {
            sum = 0;
            max_sum = max(max_sum, cur);
        }
    }

    cout << max_sum << endl;
    return 0;
}