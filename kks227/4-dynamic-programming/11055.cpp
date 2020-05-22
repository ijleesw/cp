#include "bits/stdc++.h"
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];
    // 1 100 2 50 60 3 5 6 7 8

    vector<int> sum(n, 0);
    for (int i = 0; i < n; ++i) {
        int max_sum = arr[i];
        for (int j = 0; j < n; ++j) {
            if (arr[j] < arr[i]) max_sum = max(max_sum, sum[j] + arr[i]);
        }
        sum[i] = max(sum[i], max_sum);
    }

    cout << *max_element(begin(sum), end(sum)) << endl;
    return 0;
}