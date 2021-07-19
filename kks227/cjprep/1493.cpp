#include "bits/stdc++.h"
using namespace std;

static constexpr long kInvalid = -1;

long fill_box(vector<long>* cubes, const long L, const long W, const long H)
{
    const auto l = min(L, min(W, H));
    const auto h = max(L, max(W, H));
    const auto w = L + W + H - l - h;
    // l <= w <= h

    // cout << "l, w, h : " << l << ' ' << w << ' ' << h << endl;

    if (l == 0) {
        return 0;
    }

    for (int i = cubes->size() - 1; i >= 0; --i) {
        const long cube_side = pow(2, i);
        if (cubes->at(i) == 0 || cube_side > l) {
            continue;
        }

        const auto l_cnt = min(cubes->at(i), l / cube_side);
        const auto w_cnt = min(cubes->at(i) / l_cnt, w / cube_side);
        const auto h_cnt = min(cubes->at(i) / l_cnt / w_cnt, h / cube_side);

        // cout << "  cnt : " << l_cnt << ' ' << w_cnt << ' ' << h_cnt << endl;

        auto cube_cnt = l_cnt * w_cnt * h_cnt;
        cubes->at(i) -= cube_cnt;

        const auto l_rem = l - l_cnt * cube_side;
        const auto w_rem = w - w_cnt * cube_side;
        const auto h_rem = h - h_cnt * cube_side;

        const auto c1 = fill_box(&(*cubes), l_rem, w, h);
        if (c1 < 0) {
            return kInvalid;
        }

        const auto c2 = fill_box(&(*cubes), l - l_rem, w_rem, h);
        if (c2 < 0) {
            return kInvalid;
        }

        const auto c3 = fill_box(&(*cubes), l - l_rem, w - w_rem, h_rem);
        if (c3 < 0) {
            return kInvalid;
        }

        return cube_cnt + c1 + c2 + c3;
    }

    return kInvalid;
}

int main()
{
    long L, W, H;
    vector<long> cube_cnt(21, 0);

    cin >> L >> W >> H;
    long N;
    cin >> N;
    while (N--) {
        long a, b;
        cin >> a >> b;
        cube_cnt[a] = b;
    }

    cout << fill_box(&cube_cnt, L, W, H) << endl;

    return 0;
}