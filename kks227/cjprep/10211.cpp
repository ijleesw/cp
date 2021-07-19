#include "bits/stdc++.h"
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> presum(N + 1, 0);
        for (int i = 0; i < N; ++i) {
            int x;
            cin >> x;
            presum[i + 1] = presum[i] + x;
        }
        int max_sum = numeric_limits<int>::min();
        for (int i = 0; i <= N; ++i) {
            for (int j = i + 1; j <= N; ++j) {
                max_sum = max(max_sum, presum[j] - presum[i]);
            }
        }
        cout << max_sum << endl;
    }

    return EXIT_SUCCESS;
}
