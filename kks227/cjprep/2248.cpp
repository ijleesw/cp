#include "bits/stdc++.h"
using namespace std;

long N, M, K;
long dp[33][33]{};

void build_dp()
{
    for (int i = 0; i < 33; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (j == 0 || i == j) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
        }
    }
}

void skip(const int rem_n, const int rem_bit, const long rem_cnt)
{
    if (rem_n == 0) {
        return;
    }
    if (rem_bit == 0) {
        for (int i = 0; i < rem_n; ++i) {
            putchar('0');
        }
        return;
    }
    const long pivot = accumulate(dp[rem_n - 1], dp[rem_n - 1] + rem_bit + 1, 0);
    if (rem_cnt < pivot) {
        putchar('0');
        skip(rem_n - 1, rem_bit, rem_cnt);
    } else {
        putchar('1');
        skip(rem_n - 1, rem_bit - 1, rem_cnt - pivot);
    }
}

int main()
{
    cin >> N >> M >> K;

    build_dp();
    skip(N, M, K - 1);

    return EXIT_SUCCESS;
}
