#include "bits/stdc++.h"
using namespace std;

int bt(const int last, const int rem) {
    if (rem == 0) {
        return 1;
    }

    int res = 0;

    if (last == 0) {
        for (int i = 3; i <= rem; ++i) {
            if (rem % i == 0) {
                res = max(res, bt(i, rem - i));
            }
        }

    } else {
        for (int i = last * 2; i <= rem; i += last) {
            if (rem % i == 0) {
                res = max(res, bt(i, rem - i));
            }
        }
    }

    return res == 0 ? res : res + 1;
}

int solve() {
    int N;
    cin >> N;
    return bt(0, N) - 1;
}

int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cout << "Case #" << t << ": " << solve() << endl;
    }

    return 0;
}
