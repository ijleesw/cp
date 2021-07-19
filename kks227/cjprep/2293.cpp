#include "bits/stdc++.h"
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> arr(N);
    for (auto& x : arr) {
        cin >> x;
    }
    vector<int> cnt(K + 1, 0);
    cnt[0] = 1;
    for (const auto x : arr) {
        for (int i = x; i <= K; ++i) {
            cnt[i] += cnt[i - x];
        }
    }
    cout << cnt[K] << endl;

    return EXIT_SUCCESS;
}
