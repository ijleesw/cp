#include "bits/stdc++.h"
using namespace std;
using pii = pair<int, int>;

namespace {

int upper_pow2(const int n)
{
    int res = 1;
    while (res < n) {
        res *= 2;
    }
    return res;
}

void build(vector<pii>& seg)
{
    const int N_2 = seg.size() / 2;
    for (int i = N_2 - 1; i >= 1; --i) {
        const auto left = seg[i * 2];
        const auto right = seg[i * 2 + 1];
        seg[i].first = min(left.first, right.first);
        seg[i].second = max(left.second, right.second);
    }
}

pii minmax(const vector<pii>& seg, const int cur, const int cur_l, const int cur_r, const int tgt_l, const int tgt_r)
{
    if (tgt_r < cur_l || cur_r < tgt_l) {
        return {INT_MAX, INT_MIN};

    } else if (tgt_l <= cur_l && cur_r <= tgt_r) {
        return seg[cur];

    } else {
        const int cur_m = (cur_l + cur_r) / 2;
        const auto left = minmax(seg, cur * 2, cur_l, cur_m, tgt_l, tgt_r);
        const auto right = minmax(seg, cur * 2 + 1, cur_m + 1, cur_r, tgt_l, tgt_r);
        return {min(left.first, right.first), max(left.second, right.second)};
    }
}

}  // namespace

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    const int N_2 = upper_pow2(N);
    vector<pii> seg(N_2 * 2, {INT_MAX, INT_MIN});   // first: min, second: max
    for (int i = 0; i < N; ++i) {
        int x;
        scanf("%d", &x);
        seg[N_2 + i] = {x, x};
    }
    build(seg);

    for (int i = 0; i < M; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        const auto res = minmax(seg, 1, 0, N_2 - 1, --a, --b);
        printf("%d %d\n", res.first, res.second);
    }

    return EXIT_SUCCESS;
}