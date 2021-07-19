#include "bits/stdc++.h"
using namespace std;

double solve() {
    int N, K;
    cin >> N >> K;
    vector<int> arr(N);
    for (auto& n : arr) {
        cin >> n;
    }
    sort(begin(arr), end(arr));
    arr.resize(unique(begin(arr), end(arr)) - begin(arr));

    vector<int> cands;
    for (int i = 1; i < arr.size(); ++i) {
        const int between = arr[i] - arr[i - 1] - 1;
        const int cand = max(0, (between + 1) / 2);
        cands.push_back(cand);
    }
    cands.push_back(arr.front() - 1);
    cands.push_back(K - arr.back());

    sort(begin(cands), end(cands), greater<int>());

    int res = 0;
    for (int i = 0; i < min(2, (int)cands.size()); ++i) {
        res += cands[i];
    }

    for (int i = 1; i < arr.size(); ++i) {
        const int between = arr[i] - arr[i - 1] - 1;
        res = max(res, between);
    }

    return double(res) / K;
}

int main()
{
    int T;
    cin >> T;
    cout << setprecision(7) << fixed << endl;
    for (int t = 1; t <= T; ++t) {
        cout << "Case #" << t << ": " << solve() << endl;
    }

    return 0;
}
