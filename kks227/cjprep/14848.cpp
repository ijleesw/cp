#include "bits/stdc++.h"
using namespace std;

long getGcd(long a, long b)
{
    if (a < b) {
        swap(a, b);
    }
    // a >= b
    if (b == 0) {
        return a;
    } else {
        return getGcd(b, a % b);
    }
}

int main()
{
    long N, K;
    cin >> N >> K;
    vector<long> nums(K);
    for (auto& n : nums) {
        cin >> n;
    }
    // end of input

    long erased = 0;

    for (int bit = 1; bit < (1 << K); ++bit) {
        long lcm = 1;
        int cnt = 0;
        for (int i = 0; i < K; ++i) {
            if (bit & (1 << i)) {
                ++cnt;
                lcm = lcm * nums[i] / getGcd(lcm, nums[i]);
            }
        }

        if (cnt % 2 == 1) {
            erased += N / lcm;
        } else {
            erased -= N / lcm;
        }
    }
    cout << N - erased << endl;

    return EXIT_SUCCESS;
}