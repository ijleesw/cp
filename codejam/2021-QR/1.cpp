#include "bits/stdc++.h"
using namespace std;

int solve() {
    int N;
    cin >> N;
    vector<int> arr(N);
    for (auto& n : arr) {
        cin >> n;
    }
    int res = 0;
    for (int i = 0; i < N - 1; ++i) {
        const auto it = min_element(begin(arr) + i, end(arr));
        reverse(begin(arr) + i, it + 1);
        res += (it - begin(arr) - i + 1);
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
