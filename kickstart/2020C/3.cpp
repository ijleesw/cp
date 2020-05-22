#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void Handle() {
    // handle input
    int N; cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; ++i) cin >> arr[i];

    // precompute squares
    const int maxVal = *max_element(begin(arr), end(arr));
    vector<int> tgts;
    for (int i = 0; i*i <= maxVal * N; ++i) tgts.push_back(i*i);

    // compute offset
    const int offset = max(maxVal, -1 * *min_element(begin(arr), end(arr))) * N;
    vector<int> prefixCount(offset*2+1, 0);
    prefixCount[offset + 0] = 1;

    int prefixSum = 0;
    ll countSum = 0;

    for (int i = 0; i < N; ++i) {
        prefixSum += arr[i];
        for (const auto sq : tgts) {
            const int tgtVal = prefixSum - sq;
            if (offset + tgtVal >= 0) {
                countSum += prefixCount[offset + tgtVal];
            }
        }
        ++prefixCount[offset + prefixSum];
    }

    printf("%lld\n", countSum);
}

int main() {
    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        printf("Case #%d: ", t);
        Handle();
    }
    return 0;
}
