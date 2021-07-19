#include "bits/stdc++.h"
using namespace std;

static constexpr int kNop = -1;

// base: 1-based
int get(vector<vector<int>>& dp, const vector<int>& from, const vector<int>& to, const int base, const int offset)
{
    if (base >= dp.size()) {
        return 0;
    }
    auto& cur = dp[base][offset];
    if (cur != kNop) {
        return cur;
    }

    const int from_num = (offset + from[base - 1]) % 10;
    const int to_num = to[base - 1];

    const int left_spin = (to_num - from_num + 10) % 10;
    const int right_spin = 10 - left_spin;
    const int left_offset = (offset + left_spin) % 10;

    const int left = left_spin + get(dp, from, to, base + 1, left_offset);
    const int right = right_spin + get(dp, from, to, base + 1, offset);
    return cur = min(left, right);
}

void print(vector<vector<int>>& dp, const vector<int>& from, const vector<int>& to, const int base, const int offset)
{
    if (base >= dp.size()) {
        return;
    }
    const auto cur = dp[base][offset];

    const int from_num = (offset + from[base - 1]) % 10;
    const int to_num = to[base - 1];

    const int left_spin = (to_num - from_num + 10) % 10;
    const int right_spin = 10 - left_spin;
    const int left_offset = (offset + left_spin) % 10;

    if (get(dp, from, to, base + 1, left_offset) == cur - left_spin) {
        if (base > 0) {
            cout << base << ' ' << left_spin << endl;
        }
        print(dp, from, to, base + 1, left_offset);
    } else {
        if (base > 0) {
            cout << base << ' ' << -right_spin << endl;
        }
        print(dp, from, to, base + 1, offset);
    }
}

int main()
{
    int N;
    cin >> N;
    vector<int> from;
    vector<int> to;
    for (int i = 0; i < N; ++i) {
        char c;
        cin >> c;
        from.push_back(c - '0');
    }
    for (int i = 0; i < N; ++i) {
        char c;
        cin >> c;
        to.push_back(c - '0');
    }

    vector<vector<int>> dp(N + 1, vector<int>(10, kNop));
    const int cnt = get(dp, from, to, 0, 0);
    cout << cnt << endl;

    print(dp, from, to, 0, 0);

    return EXIT_SUCCESS;
}