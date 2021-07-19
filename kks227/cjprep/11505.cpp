#include "bits/stdc++.h"
using namespace std;

static constexpr long kMod = 1000000007;

namespace {

long upper_pow2(long n)
{
    long res = 1;
    while (res < n) {
        res *= 2;
    }
    return res;
}

void build(vector<long>& seg)
{
    int N_2 = seg.size() / 2;
    for (int i = N_2 - 1; i >= 1; --i) {
        seg[i] = seg[i * 2] * seg[i * 2 + 1] % kMod;
    }
}

void update(vector<long>& seg, const int idx, const long val)
{
    int cur_idx = seg.size() / 2 + idx;
    seg[cur_idx] = val;
    while (cur_idx > 1) {
        cur_idx /= 2;
        seg[cur_idx] = seg[cur_idx * 2] * seg[cur_idx * 2 + 1] % kMod;
    }
}

// l, r : inclusive
long product(const vector<long>& seg, const int cur, const int cur_l, const int cur_r, const int tgt_l, const int tgt_r)
{
    if (tgt_r < cur_l || cur_r < tgt_l) {
        return 1;

    } else if (tgt_l <= cur_l && cur_r <= tgt_r) {
        return seg[cur];

    } else {
        const int cur_m = (cur_l + cur_r) / 2;
        return product(seg, cur * 2, cur_l, cur_m, tgt_l, tgt_r)
               * product(seg, cur * 2 + 1, cur_m + 1, cur_r, tgt_l, tgt_r) % kMod;
    }
}

void print(const vector<long>& seg)
{
    cout << endl << "===\n";
    for (int i = 1; i < seg.size(); ++i) {
        if (i & (i - 1)) {
            cout << ' ';
        } else {
            cout << endl;
        }
        cout << seg[i];
    }
    cout << "\n===\n";
}

}  // namespace

int main()
{
    int N, M, K;
    cin >> N >> M >> K;
    const int N_2 = upper_pow2(N);
    vector<long> seg(N_2 * 2, 1);
    for (int i = N_2; i < N_2 + N; ++i) {
        scanf("%ld", &seg[i]);
    }
    build(seg);

    for (int i = 0; i < M + K; ++i) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if (a == 1) {
            update(seg, --b, c);
        } else if (a == 2) {
            printf("%ld\n", product(seg, 1, 0, N - 1, --b, --c));
        } else {
            assert(false);
        }
    }

    return EXIT_SUCCESS;
}