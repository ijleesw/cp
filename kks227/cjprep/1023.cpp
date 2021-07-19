#include "bits/stdc++.h"
using namespace std;

long N, K;
long dp[51][26]{};
string res;

long count(const int pos, const int nopen)
{
    if (pos == N) {
        return 0;
    }
    auto& cur = dp[pos][nopen];
    if (cur != -1) {
        return cur;
    }
    if (N - pos == nopen) {
        return cur = (1L << (N - pos)) - 1;
    }
    const long ifopened = count(pos + 1, nopen + 1);
    const long ifclosed = (nopen == 0 ? (1L << (N - pos - 1)) : count(pos + 1, nopen - 1));
    return cur = ifopened + ifclosed;
}

void sequential(const int pos, long rem_cnt)
{
    if (pos == N) {
        return;
    }
    const long pivot = (1L << (N - pos - 1));
    if (rem_cnt < pivot) {
        res.push_back('(');
        sequential(pos + 1, rem_cnt);
    } else {
        res.push_back(')');
        sequential(pos + 1, rem_cnt - pivot);
    }
}

void skip(const int pos, const int nopen, const long rem_cnt)
{
    if (pos == N) {
        return;
    } else if (nopen == N - pos) {
        sequential(pos, rem_cnt);
        return;
    }

    const long pivot = count(pos + 1, nopen + 1);
    if (rem_cnt < pivot) {
        res.push_back('(');
        skip(pos + 1, nopen + 1, rem_cnt);
    } else {
        res.push_back(')');
        if (nopen == 0) {
            sequential(pos + 1, rem_cnt - pivot);
        } else {
            skip(pos + 1, nopen - 1, rem_cnt - pivot);
        }
    }
}

int main()
{
    cin >> N >> K;

    memset(dp, -1, sizeof(dp));

    if (N % 2 == 1) {
        sequential(0, K);
        cout << res << endl;
    } else {
        if (K >= count(0, 0)) {
            cout << -1 << endl;
        } else {
            skip(0, 0, K);
            cout << res << endl;
        }
    }

    return EXIT_SUCCESS;
}
