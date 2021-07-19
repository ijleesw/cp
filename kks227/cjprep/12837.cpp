#include "bits/stdc++.h"
using namespace std;

namespace {

int upper_pow2(int n)
{
    int res = 1;
    while (res < n) {
        res *= 2;
    }
    return res;
}

void update(vector<long>& seg, const int idx, const long val)
{
    int cur = seg.size() / 2 + idx;
    while (cur >= 1) {
        seg[cur] += val;
        cur /= 2;
    }
}

long agg(const vector<long>& seg, const int cur, const int cur_l, const int cur_r, const int tgt_l, const int tgt_r)
{
    if (tgt_r < cur_l || cur_r < tgt_l) {
        return 0;
    } else if (tgt_l <= cur_l && cur_r <= tgt_r) {
        return seg[cur];
    } else {
        const int cur_m = (cur_l + cur_r) / 2;
        return agg(seg, cur * 2, cur_l, cur_m, tgt_l, tgt_r) + agg(seg, cur * 2 + 1, cur_m + 1, cur_r, tgt_l, tgt_r);
    }
}

}   // namespace

int main()
{
    int N, Q;
    scanf("%d %d", &N, &Q);
    const int N_2 = upper_pow2(N);
    vector<long> seg(N_2 * 2, 0);

    for (int i = 0; i < Q; ++i) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if (a == 1) {
            update(seg, --b, c);
        } else {
            printf("%ld\n", agg(seg, 1, 0, N_2 - 1, --b, --c));
        }
    }

    return EXIT_SUCCESS;
}