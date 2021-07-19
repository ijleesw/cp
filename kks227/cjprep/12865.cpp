#include "bits/stdc++.h"
using namespace std;

static constexpr int kNotReached = -1;
static_assert(kNotReached < 0, "");

int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> vals(K + 1, kNotReached);
    vals[0] = 0;

    while (N--) {
        int W, V;
        cin >> W >> V;

        for (int i = K - W; i >= 0; --i) {
            if (vals[i] != kNotReached) {
                vals[i + W] = max(vals[i + W], vals[i] + V);
            }
        }
    }

    cout << *max_element(begin(vals), end(vals)) << endl;
    return 0;
}