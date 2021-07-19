#include "bits/stdc++.h"
using namespace std;

int upper_pow2(const int n)
{
    return 1 << (32 - __builtin_clz(n - 1));
}

namespace detail {

int sum(vector<int>& seg, const int cur, const int cur_l, const int cur_r, const int tgt_l, const int tgt_r)
{
    if (tgt_r < cur_l || cur_r < tgt_l) {
        return 0;
    } else if (tgt_l <= cur_l && cur_r <= tgt_r) {
        return seg[cur];
    } else {
        const int cur_m = (cur_l + cur_r) / 2;
        return sum(seg, cur * 2, cur_l, cur_m, tgt_l, tgt_r) + sum(seg, cur * 2 + 1, cur_m + 1, cur_r, tgt_l, tgt_r);
    }
}

// taste : inclusive
int count(vector<int>& seg, const int taste)
{
    const int N2 = seg.size() / 2;
    return sum(seg, 1, 0, N2 - 1, 1, taste);
}

}   // detail

void add(vector<int>& seg, const int taste, const int cnt)
{
    int cur = seg.size() / 2 + taste;
    while (cur >= 1) {
        seg[cur] += cnt;
        cur /= 2;
    }
}

int get_taste(vector<int>& seg, const int rank)
{
    int l = 1;
    int r = 1000000;
    int res = -1;
    while (l <= r) {
        const int m = (l + r) / 2;
        const int cnt = detail::count(seg, m);
        if (cnt < rank) {   // m is wrong
            l = m + 1;
        } else {            // m can be answer
            res = m;
            r = m - 1;
        }
    }
    assert(res != -1);
    return res;
}

int get_taste2(vector<int>& seg, int rank)
{
    int cur = 1;
    const int N2 = seg.size() / 2;
    --rank;

    while (cur < N2) {
        if (rank < seg[cur * 2]) {
            cur = cur * 2;
        } else {
            rank -= seg[cur * 2];
            cur = cur * 2 + 1;
        }
    }
    return cur - N2;
}

int main()
{
    int M;
    cin >> M;

    const int N2 = 1048576;
    vector<int> seg(N2 * 2, 0);

    for (int i = 0; i < M; ++i) {
        int a;
        scanf("%d", &a);
        if (a == 1) {
            int b;
            scanf("%d", &b);
            const int taste = get_taste2(seg, b);
            printf("%d\n", taste);
            add(seg, taste, -1);

        } else {
            int b, c;
            scanf("%d %d", &b, &c);
            add(seg, b, c);
        }
    }

    return EXIT_SUCCESS;
}