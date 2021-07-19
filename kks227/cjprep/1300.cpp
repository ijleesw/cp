#include "bits/stdc++.h"
using namespace std;

int count(const int N, const int val)
{
    int cnt = 0;
    const auto last = min(val, N);
    for (int i = 1; i <= last; ++i) {
        cnt += min(i * N, val) / i;
    }
    return cnt;
}

int main()
{
    int N, K;
    cin >> N >> K;

    int l = 1;
    int r = N * N;
    int res = -1;

    while (l <= r) {
        const auto m = (l + r) / 2;

        if (count(N, m) >= K) {
            res = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    assert(res != -1);

    cout << res << endl;

    return 0;
}