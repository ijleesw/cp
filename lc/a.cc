#include "bits/stdc++.h"
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> arr(N);
    for (auto& v : arr) {
        cin >> v;
    }

    int l = 0;
    int r = N - 1;
    int res = 0;
    while (l < r) {
        const auto m = (l + r) / 2;
        if (arr[m] == arr[m + 1]) {
            if ((m - l) % 2 == 0) {
                l = m + 2;
            } else {
                r = m - 1;
            }
        } else {
            if ((m - l) % 2 == 0) {
                r = m;
            } else {
                l = m + 1;
            }
        }
    }
    cout << arr[l] << endl;
}
