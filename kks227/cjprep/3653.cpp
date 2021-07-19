#include "bits/stdc++.h"
using namespace std;

int upper_pow2(int n)
{
    return 1 << (32 - __builtin_clz(n - 1));
}

// pos : 0-based
void add(vector<int>& seg, const int pos, const int val)
{
    int cur = seg.size() / 2 + pos;
    while (cur >= 1) {
        seg[cur] += val;
        cur /= 2;
    }
}

// *_{l,r} : 0-based
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

void print(const vector<int>& seg)
{
    const int N_2 = seg.size() / 2;
    for (int i = N_2; i < seg.size(); ++i) {
        cout << seg[i] << ' ';
    }
    cout << endl;
}

void solve()
{
    int N, M;
    cin >> N >> M;

    // const int N_2 = upper_pow2(N + M + 1);
    const int N_2 = upper_pow2(max(N, M) * 2 + 1);
    vector<int> seg(N_2 * 2, 0);
    vector<int> pos(N);     // 0-based
    int front_pos = N_2 / 2;
    for (int i = 0; i < N; ++i) {
        pos[i] = front_pos + i;
        add(seg, pos[i], 1);
    }

    for (int i = 0; i < M; ++i) {
        --front_pos;

        int x;
        scanf("%d", &x);
        --x;

        const int cur_pos = pos[x];
        add(seg, cur_pos, -1);
        printf("%d ", sum(seg, 1, 0, N_2 - 1, 0, cur_pos));
        add(seg, front_pos, 1);
        pos[x] = front_pos;
    }
    cout << endl;
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