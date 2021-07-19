#include "bits/stdc++.h"
using namespace std;

string solve() {
    int N, C;
    cin >> N >> C;
    int mincnt = N - 1;
    int maxcnt = N * (N + 1) / 2 - 1;
    if (C < mincnt || maxcnt < C) {
        return "IMPOSSIBLE";
    }

    vector<int> stride(N - 1, 1);
    C -= (N - 1);
    for (int i = 0; i < N - 1; ++i) {
        int curcnt = min(i + 1, C);
        stride[i] += curcnt;
        C -= curcnt;
    }

    vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        arr[i] = i + 1;
    }

    for (int i = 0; i < N - 1; ++i) {
        int l = (N - 2) - i;
        int r = l + stride[i];
        reverse(begin(arr) + l, begin(arr) + r);
    }

    string res;
    for (const auto n : arr) {
        res.append(to_string(n)).append(" ");
    }
    return res;
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
