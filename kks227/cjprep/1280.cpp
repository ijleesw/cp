#include "bits/stdc++.h"
using namespace std;
using pll = pair<long, long>;

static constexpr long kMod = 1000000007;

struct Elt
{
    long l, r;
    long lsum, rsum;
    long cnt;

    // TODO: use static constexpr var
    Elt() : l(-1), r(-1), lsum(0), rsum(0), cnt(0) {}
    bool empty() const { return l < 0; }

    Elt operator+(const Elt& rhs) const {
        const auto& lhs = *this;
        if (lhs.empty()) {
            return rhs;
        } else if (rhs.empty()) {
            return lhs;
        }
        assert(lhs.l <= lhs.r && lhs.r <= rhs.l && rhs.l <= rhs.r && "wrong order");
        Elt res;
        res.l = lhs.l;
        res.r = rhs.r;
        res.lsum = lhs.lsum + rhs.lsum + (rhs.l - lhs.l) * rhs.cnt;
        res.rsum = lhs.rsum + rhs.rsum + (rhs.r - lhs.r) * lhs.cnt;
        res.cnt = lhs.cnt + rhs.cnt;
        return res;
    }
};

namespace detail {

void plant(vector<Elt>& seg, const long pos, const long val)
{
    long cur = seg.size() / 2 + pos;
    // TODO: move to Elt
    seg[cur].l = seg[cur].r = val;
    seg[cur].lsum = seg[cur].rsum = 0;
    seg[cur].cnt = 1;
    while (cur > 1) {
        cur /= 2;
        seg[cur] = seg[cur * 2] + seg[cur * 2 + 1];
    }
}

Elt sum(const vector<Elt>& seg, const int cur, const int cur_l, const int cur_r, const int tgt_l, const int tgt_r)
{
    if (tgt_r < cur_l || cur_r < tgt_l) {
        return {};
    } else if (tgt_l <= cur_l && cur_r <= tgt_r) {
        return seg[cur];
    } else {
        const int cur_m = (cur_l + cur_r) / 2;
        return sum(seg, cur * 2, cur_l, cur_m, tgt_l, tgt_r) + sum(seg, cur * 2 + 1, cur_m + 1, cur_r, tgt_l, tgt_r);
    }
}

long cost(const vector<Elt>& seg, const long pos)
{
    const int N_2 = seg.size() / 2;
    const auto left = sum(seg, 1, 0, N_2 - 1, 0, pos);
    const auto right = sum(seg, 1, 0, N_2 - 1, pos, N_2 - 1);
    return left.rsum + right.lsum;
}

}   // namespace detail

long upper_pow2(const long N)
{
    long res = 1;
    while (res < N) {
        res *= 2;
    }
    return res;
}

long plantAndPay(vector<Elt>& seg, const long pos, const long val)
{
    detail::plant(seg, pos, val);
    return detail::cost(seg, pos);
}

int main()
{
    long N;
    cin >> N;
    vector<pll> nums(N);    // first: pos, second: orig idx
    for (long i = 0; i < N; ++i) {
        long x;
        scanf("%ld", &x);
        nums[i] = {x, i};
    }
    sort(begin(nums), end(nums));

    vector<long> pos(N);    // orig idx -> new idx
    for (long i = 0; i < N; ++i) {
        pos[nums[i].second] = i;
    }

    const auto N_2 = upper_pow2(N);
    vector<Elt> seg(N_2 * 2);

    long prod = 1;
    for (int i = 0; i < N; ++i) {
        const auto cost = plantAndPay(seg, pos[i], nums[pos[i]].first) % kMod;
        if (i >= 1) {
            prod *= cost;
            prod %= kMod;
        }
    }
    cout << prod << endl;

    return EXIT_SUCCESS;
}