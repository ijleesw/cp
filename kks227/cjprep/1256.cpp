#include "bits/stdc++.h"
using namespace std;

static constexpr int kNop = -1;
static constexpr int kMax = 1000000007;

int N, M, K;
int dp[201][201]{};
string res;

void build_dp()
{
    for (int i = 0; i <= N + M; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (j == 0 || i == j) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = min(kMax, dp[i - 1][j] + dp[i - 1][j - 1]);
            }
        }
    }
}

void skip(const int rem_N, const int rem_M, const int rem_cnt)
{
    if (rem_N == 0) {
        for (int i = 0; i < rem_M; ++i) {
            res.push_back('z');
        }
        return;
    } else if (rem_M == 0) {
        for (int i = 0; i < rem_N; ++i) {
            res.push_back('a');
        }
        return;
    }
    
    const int pivot = dp[rem_N + rem_M - 1][rem_M];
    if (pivot <= rem_cnt) {
        res.push_back('z');
        skip(rem_N, rem_M - 1, rem_cnt - pivot);
    } else {
        res.push_back('a');
        skip(rem_N - 1, rem_M, rem_cnt);
    }
}


int main()
{
    cin >> N >> M >> K;

    build_dp();

    if (K > dp[N + M][N]) {
        cout << -1 << endl;
    } else {
        skip(N, M, K - 1);
        cout << res << endl;
    }

    return EXIT_SUCCESS;
}
