#include "bits/stdc++.h"
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> presum(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        int x;
        // cin >> x;
        scanf("%d", &x);
        presum[i + 1] = (presum[i] + x) % M;
    }
    // end of input

    vector<int> remcnt(M, 0);
    for (const auto x : presum) {
        ++remcnt[x];
    }
    long sum = 0;
    for (const auto cnt : remcnt) {
        sum += static_cast<long>(cnt) * (cnt - 1) / 2;
    }
    cout << sum << endl;

    return EXIT_SUCCESS;
}
