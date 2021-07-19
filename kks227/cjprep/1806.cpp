#include "bits/stdc++.h"
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> arr(N);
    for (auto& x : arr) {
        cin >> x;
    }

    int l = 0;
    int r = 0;
    int sum = 0;
    int len = INT_MAX;
    while (true) {
        if (sum >= M) {
            sum -= arr[l++];
        } else {    // sum < M
            if (r == N) {
                break;
            } else {
                sum += arr[r++];
            }
        }
        if (sum >= M) {
            len = min(len, r - l);
        }
    }
    cout << (len == INT_MAX ? 0 : len) << endl;

    return EXIT_SUCCESS;
}
