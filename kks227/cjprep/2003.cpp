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
    int cnt = 0;
    while (true) {
        if (sum >= M) {
            sum -= arr[l++];
        } else {
            if (r == N) {
                break;
            } else {
                sum += arr[r++];
            }
        }
        if (sum == M) {
            ++cnt;
        }
    }
    cout << cnt << endl;

    return EXIT_SUCCESS;
}
