#include "bits/stdc++.h"
using namespace std;

static constexpr long kMax = (1L << 32);

long N, M, K;
long dparr[11][221][221];
vector<int> res;

long dp(const long pos, const long cur_val, const long rem_m)
{
    if (pos >= N) {
        return 0;
    } else if (pos == N - 1) {
        return (int)(rem_m == 0);
    }
    auto& cur = dparr[pos][cur_val][rem_m];
    if (cur != -1) {
        return cur;
    }
    cur = 0;
    const int max_next_val = rem_m / (N - pos - 1);
    for (int i = cur_val; i <= max_next_val; ++i) {
        cur += dp(pos + 1, i, rem_m - i);
    }
    return cur;
}

void sequential(const int pos, const int cur_val, long rem_m)
{
    assert(cur_val * (N - pos) <= rem_m && "invalid case");
    for (int i = pos; i < N - 1; ++i) {
        res.push_back(cur_val);
        rem_m -= cur_val;
    }
    res.push_back(rem_m);
}

void skip(const int pos, const int cur_val, const long rem_m, const long rem_cnt)
{
    if (pos == N) {
        return;
    } else if (pos == N - 1) {
        assert(rem_m == 0 && "rem_m should be 0 this case");
        assert(rem_cnt == 0 && "rem_cnt should be 0 this case");
        res.push_back(cur_val);
        return;
    } else if (rem_cnt == 0) {
        sequential(pos, cur_val, rem_m + cur_val);
        return;
    }

    const long pivot = dp(pos, cur_val, rem_m);
    if (rem_cnt < pivot) {
        res.push_back(cur_val);
        if (pos == N - 2) {
            skip(pos + 1, rem_m, 0, rem_cnt);
        } else {
            skip(pos + 1, cur_val, rem_m - cur_val, rem_cnt);
        }
    } else {
        skip(pos, cur_val + 1, rem_m - 1, rem_cnt - pivot);
    }
}

int main()
{
    cin >> N >> M >> K;

    memset(dparr, -1, sizeof(dparr));
    if (N == 1 && M > 1) {
        skip(0, M, 0, K - 1);
    } else {
        skip(0, 1, M - 1, K - 1);
    }
    for (auto n : res) {
        cout << n << ' ';
    }
    cout << endl;

    return EXIT_SUCCESS;
}
