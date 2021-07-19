#include "bits/stdc++.h"
using namespace std;
using pii = pair<int, int>;

static constexpr int kBad = 1;
static constexpr int kGood = 2;

int cut(const vector<vector<int>>& board, const pii& ul, const pii& br, const bool is_hori)
{
    const auto up = ul.first;
    const auto left = ul.second;
    const auto bottom = br.first;
    const auto right = br.second;

    if (up == bottom || left == right) {
        return 0;
    }
    if (bottom - up == 1 && right - left == 1) {
        return static_cast<int>(board[up][left] == kGood);
    }

    int bad_cnt = 0;
    int good_cnt = 0;
    int cnt = 0;
    if (is_hori) {
        for (int i = up; i < bottom; ++i) {
            bool has_bad = false;
            bool has_good = false;
            for (int j = left; j < right; ++j) {
                if (board[i][j] == kBad) {
                    ++bad_cnt;
                    has_bad = true;
                }
                if (board[i][j] == kGood) {
                    ++good_cnt;
                    has_good = true;
                }
            }
            if (has_bad and not has_good) {
                cnt += cut(board, pii(up, left), pii(i, right), !is_hori)
                       * cut(board, pii(i + 1, left), pii(bottom, right), !is_hori);
            }
        }
    } else {
        for (int i = left; i < right; ++i) {
            bool has_bad = false;
            bool has_good = false;
            for (int j = up; j < bottom; ++j) {
                if (board[j][i] == kBad) {
                    ++bad_cnt;
                    has_bad = true;
                }
                if (board[j][i] == kGood) {
                    ++good_cnt;
                    has_good = true;
                }
            }
            if (has_bad and not has_good) {
                cnt += cut(board, pii(up, left), pii(bottom, i), !is_hori)
                       * cut(board, pii(up, i + 1), pii(bottom, right), !is_hori);
            }
        }
    }

    return cnt + static_cast<int>(good_cnt == 1 && bad_cnt == 0);
}

int main()
{
    int N;
    cin >> N;
    vector<vector<int>> board(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> board[i][j];
        }
    }


    const auto res = cut(board, pii(0, 0), pii(N, N), true) + cut(board, pii(0, 0), pii(N, N), false);
    cout << (res > 0 ? res : -1) << endl;
    return 0;
}