#include "bits/stdc++.h"
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> bals(N);
    for (int i = 0; i < N; ++i) cin >> bals[i];

    auto getLeft  = [&](int i) { return (i + N - 1) % N; };
    auto getRight = [&](int i) { return (i + 1) % N; };

    int cur_idx = 0;
    for (int i = 0; i < N; ++i) {
        cout << cur_idx+1 << ' ';
        if (i == N-1) break;

        int cur_move = bals[cur_idx];
        bals[cur_idx] = 0;

        if (cur_move > 0) {
            while (bals[cur_idx] == 0) cur_idx = getRight(cur_idx);
            while (--cur_move) {
                cur_idx = getRight(cur_idx);
                while (bals[cur_idx] == 0) cur_idx = getRight(cur_idx);
            }
        } else {
            while (bals[cur_idx] == 0) cur_idx = getLeft(cur_idx);
            while (++cur_move) {
                cur_idx = getLeft(cur_idx);
                while (bals[cur_idx] == 0) cur_idx = getLeft(cur_idx);
            }
        }
    }
    cout << endl;
    return 0;
}