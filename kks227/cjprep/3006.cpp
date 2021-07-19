#include "bits/stdc++.h"
using namespace std;

namespace {

int upper_pow2(int n)
{
    int res = 1;
    while (res < n) {
        res <<= 1;
    }
    return res;
}

void build(vector<int>& seg)
{
    for (int i = seg.size() / 2 - 1; i >= 1; --i) {
        seg[i] = seg[i * 2] + seg[i * 2 + 1];
    }
}

void remove(vector<int>& seg, const int idx)
{
    int cur = seg.size() / 2 + idx;
    while (cur >= 1) {
        --seg[cur];
        cur /= 2;
    }
}

int count(const vector<int>& seg, const int cur, const int cur_l, const int cur_r, const int tgt_l, const int tgt_r)
{
    if (tgt_l > tgt_r) {
        return 0;
    } else if (tgt_r < cur_l || cur_r < tgt_l) {
        return 0;
    } else if (tgt_l <= cur_l && cur_r <= tgt_r) {
        return seg[cur];
    } else {
        const int cur_m = (cur_l + cur_r) / 2;
        return count(seg, cur * 2, cur_l, cur_m, tgt_l, tgt_r) + count(seg, cur * 2 + 1, cur_m + 1, cur_r , tgt_l, tgt_r);
    }
}

}   // namespace

int main()
{
    int N;
    cin >> N;
    vector<int> pos(N);
    for (int i = 0; i < N; ++i) {
        int x;
        scanf("%d", &x);
        --x;
        pos[x] = i;
    }

    const int N_2 = upper_pow2(N);
    vector<int> seg(N_2 * 2, 0);
    for (int i = N_2; i < N_2 + N; ++i) {
        seg[i] = 1;
    }
    build(seg);

    for (int i = 0; i < N; ++i) {
        const int cur = (i % 2 == 0 ? i / 2 : N - 1 - i / 2);
        remove(seg, pos[cur]);
        if (i % 2 == 0) {
            printf("%d\n", count(seg, 1, 0, N_2 - 1, 0, pos[cur]));
        } else {
            printf("%d\n", count(seg, 1, 0, N_2 - 1, pos[cur], N - 1));
        }
    }

    return EXIT_SUCCESS;
}