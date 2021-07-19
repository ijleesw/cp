#include "bits/stdc++.h"
using namespace std;

struct MM
{
    int min, max;
    MM operator+(const MM& rhs)
    {
        const auto& lhs = *this;
        return {std::min(lhs.min, rhs.min), std::max(lhs.max, rhs.max)};
    }
};

int upper_pow2(const int n)
{
    return 1 << (32 - __builtin_clz(n - 1));
}

void build(vector<MM>& seg)
{
    const int N2 = seg.size() / 2;
    for (int i = N2 - 1; i >= 1; --i) {
        seg[i] = seg[i * 2] + seg[i * 2 + 1];
    }
}

void update(vector<MM>& seg, const int pos, const int val)
{
    int cur = seg.size() / 2 + pos;
    seg[cur] = {val, val};
    while (cur > 1) {
        cur /= 2;
        seg[cur] = seg[cur * 2] + seg[cur * 2 + 1];
    }
}

void swap(vector<MM>& seg, const int pos1, const int pos2)
{
    const int N2 = seg.size() / 2;
    const int val1 = seg[N2 + pos1].min;
    const int val2 = seg[N2 + pos2].min;
    update(seg, pos1, val2);
    update(seg, pos2, val1);
}

MM query(const vector<MM>& seg, const int cur, const int cur_l, const int cur_r, const int tgt_l, const int tgt_r)
{
    if (tgt_r < cur_l || cur_r < tgt_l) {
        return {INT_MAX, INT_MIN};  // TODO: move to MM constructor
    } else if (tgt_l <= cur_l && cur_r <= tgt_r) {
        return seg[cur];
    } else {
        const int cur_m = (cur_l + cur_r) / 2;
        return query(seg, cur * 2, cur_l, cur_m, tgt_l, tgt_r) + query(seg, cur * 2 + 1, cur_m + 1, cur_r, tgt_l, tgt_r);
    }
}

bool valid(const vector<MM>& seg, const int l, const int r)
{
    const auto res = query(seg, 1, 0, seg.size() / 2 - 1, l, r);
    return res.min == min(l, r) && res.max == max(l, r);
}

void solve()
{
    int N, M;
    cin >> N >> M;

    const int N2 = upper_pow2(N);
    vector<MM> seg(N2 * 2);
    for (int i = 0; i < N; ++i) {
        seg[N2 + i] = {i, i};
    }
    build(seg);

    for (int i = 0; i < M; ++i) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if (a == 0) {
            swap(seg, b, c);
        } else {
            printf("%s\n", valid(seg, b, c) ? "YES" : "NO");
        }
    }
}

int main()
{
    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return EXIT_SUCCESS;
}