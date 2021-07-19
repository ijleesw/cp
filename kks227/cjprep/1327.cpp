#include "bits/stdc++.h"
using namespace std;
using pii = pair<int, int>;

bool issorted(int n)
{
    int last = 10;
    while (n > 0) {
        if (n % 10 > last) {
            return false;
        }
        last = n % 10;
        n /= 10;
    }
    return true;
}

int flip(int n, const int from, const int cnt)
{
    vector<int> nums;
    nums.reserve(cnt);
    int pow10 = 1;
    for (int i = 0; i < from; ++i) {
        pow10 *= 10;
    }
    int pow10_cp = pow10;
    for (int i = 0; i < cnt; ++i) {
        nums.push_back(n / pow10_cp % 10);
        n -= nums.back() * pow10_cp;
        pow10_cp *= 10;
    }
    reverse(begin(nums), end(nums));
    pow10_cp = pow10;
    for (int i = 0; i < cnt; ++i) {
        n += nums[i] * pow10_cp;
        pow10_cp *= 10;
    }
    return n;
}

int main()
{
    int N, K;
    cin >> N >> K;
    int start = 0;
    for (int i = 0; i < N; ++i) {
        int n;
        cin >> n;
        start = start * 10 + n;
    }
    // end of input

    unordered_map<int, int> step;

    queue<pii> q;
    q.emplace(start, 0);
    while (!q.empty()) {
        const auto cur = q.front();
        q.pop();
        if (issorted(cur.first)) {
            cout << cur.second << endl;
            return EXIT_SUCCESS;
        }
        for (int i = 0; i <= N - K; ++i) {
            const auto flipped = flip(cur.first, i, K);
            const auto it = step.find(flipped);
            if (it == end(step)) {
                step[flipped] = cur.second + 1;
                q.emplace(flipped, cur.second + 1);
            } else if (it != end(step) && cur.second + 1 < it->second) {
                it->second = cur.second + 1;
                q.emplace(flipped, cur.second + 1);
            }
        }
    }
    cout << -1 << endl;
    return EXIT_SUCCESS;
}