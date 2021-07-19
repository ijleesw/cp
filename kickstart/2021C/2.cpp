#include "bits/stdc++.h"
using namespace std;

long solve() {
    long N;
    cin >> N;

    long l = 1;
    long r = N;
    long mid = 5;
    while (l <= r) {
        long m = (l + r) / 2;
        if (m < sqrt(2 * N)) {
            l = m + 1;
        } else {
            mid = m;
            r = m - 1;
        }
    }

    long res = 0;

    for (long cnt = 1; cnt <= mid; ++cnt) {
        long start = -1;
        if (cnt % 2 == 1) {
            if (N % cnt != 0) {
                continue;
            }
            const long middle = N / cnt;
            start = middle - (cnt / 2);

        } else {
            if ((N * 2) % cnt != 0) {
                continue;
            }
            const long double_middle = N * 2 / cnt;
            if (double_middle % 2 != 1) {
                continue;
            }
            start = (double_middle + 1) / 2 - (cnt / 2);
        }
        if (start >= 1) {
            // cout << "cand : " << cnt << "->" << start << endl;
            ++res;
        }
    }
    return res;
}

int main()
{
    long T;
    cin >> T;
    for (long t = 1; t <= T; ++t) {
        cout << "Case #" << t << ": " << solve() << endl;
    }

    return 0;
}
