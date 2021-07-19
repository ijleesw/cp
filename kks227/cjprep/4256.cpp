#include "bits/stdc++.h"
using namespace std;

void printPost(const vector<int>& pre, const int pre_l, const int pre_r,
               const vector<int>& in, const int in_l, const int in_r)   // pre_r, in_r : exclusive
{
    if (pre_l == pre_r) {
        return;
    }

    const auto pre_head = pre[pre_l];
    int in_head = -1;
    for (int i = in_l; i < in_r; ++i) {
        if (in[i] == pre_head) {
            in_head = i;
        }
    }
    assert(in_head != -1);

    const auto left_sz = in_head - in_l;
    const auto right_sz = in_r - in_head - 1;
    printPost(pre, pre_l + 1, pre_l + 1 + left_sz, in, in_l, in_head);
    printPost(pre, pre_l + 1 + left_sz, pre_r, in, in_head + 1, in_r);
    cout << pre_head << ' ';
}

void solve()
{
    int N;
    cin >> N;
    vector<int> pre(N);
    vector<int> in(N);
    for (auto& x : pre) {
        cin >> x;
    }
    for (auto& x : in) {
        cin >> x;
    }
    printPost(pre, 0, N, in, 0, N);
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