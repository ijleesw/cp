#include "bits/stdc++.h"
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> arr(N);
    for (auto& x : arr) {
        scanf("%d", &x);
    }
    sort(begin(arr), end(arr));

    int l = 0;
    int r = 0;
    int diff = 0;
    int mindiff = INT_MAX;

    while (true) {
        if (diff > M) {
            diff += arr[l];
            ++l;
            diff -= arr[l];
        } else {    // diff <= M
            if (r == N) {
                break;
            } else {
                diff -= arr[r];
                ++r;
                diff += arr[r];
            }
        }
        if (diff >= M) {
            mindiff = min(mindiff, diff);
        }
    }
    cout << mindiff << endl;

    return EXIT_SUCCESS;
}
