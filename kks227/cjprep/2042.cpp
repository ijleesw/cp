#include "bits/stdc++.h"
using namespace std;

// l, r : inclusive
long sum(const vector<long>& seg, const long cur, const long cur_l, const long cur_r, const long tgt_l, const long tgt_r)
{
    if (tgt_r < cur_l || cur_r < tgt_l) {
        return 0;
    } else if (tgt_l <= cur_l && cur_r <= tgt_r) {
        return seg[cur];
    } else {
        const long mid = (cur_l + cur_r) / 2;
        return sum(seg, cur * 2, cur_l, mid, tgt_l, tgt_r)
               + sum(seg, cur * 2 + 1, mid + 1, cur_r, tgt_l, tgt_r);
    }
}

int main()
{
    long N, M, K;
    cin >> N >> M >> K;

    long offset = 1;
    while (offset < N) {
        offset <<= 1;
    }
    vector<long> segtree(offset * 2);
    for (long i = 0; i < N; ++i) {
        scanf("%ld", &segtree[offset + i]);
    }
    for (long i = offset - 1; i >= 1; --i) {
        segtree[i] = segtree[i * 2] + segtree[i * 2 + 1];
    }

    for (long i = 0; i < M + K; ++i) {
        long a, b, c;
        scanf("%ld %ld %ld", &a, &b, &c);
        if (a == 1) {
            --b;
            long idx = offset + b;
            const long diff = c - segtree[idx];
            while (idx >= 1) {
                segtree[idx] += diff;
                idx /= 2;
            }

        } else if (a == 2) {
            --b;
            --c;
            printf("%ld\n", sum(segtree, 1, 0, offset - 1, b, c));

        } else {
            assert(false);
        }
    }

    return EXIT_SUCCESS;
}