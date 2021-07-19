#include "bits/stdc++.h"
using namespace std;

static constexpr size_t kMod = 1000000000;

size_t cnt[101][10][1 << 10];   // digit cnt / last digit / shown

void add_single_digit(const int tgt_idx, const int from_digit, const int to_digit)
{
    for (int i = 0; i < (1 << 10); ++i) {   // shown bit field
        cnt[tgt_idx][to_digit][i | (1 << to_digit)] += cnt[tgt_idx - 1][from_digit][i];
        cnt[tgt_idx][to_digit][i | (1 << to_digit)] %= kMod;
    }
}

void add_digits(const int tgt_idx)
{
    add_single_digit(tgt_idx, 1, 0);
    for (int j = 1; j <= 8; ++j) {
        add_single_digit(tgt_idx, j - 1, j);
        add_single_digit(tgt_idx, j + 1, j);
    }
    add_single_digit(tgt_idx, 8, 9);
}

int main()
{
    int N;
    cin >> N;

    for (int i = 1; i <= 9; ++i) {
        cnt[1][i][1 << i] = 1;
    }
    for (int i = 2; i <= N; ++i) {  // target idx
        add_digits(i);
    }

    size_t sum = 0;
    for (int i = 0; i <= 9; ++i) {
        sum += cnt[N][i][(1 << 10) - 1];
    }
    sum %= kMod;
    cout << sum << endl;

    return EXIT_SUCCESS;
}