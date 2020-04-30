#include "bits/stdc++.h"
using namespace std;

int daq(const vector<vector<int>>& board,
        int x0, int y0, int x1, int y1, bool was_hori, int d) {
    string pad(d*4, ' ');
    // printf("%sx0=%d, y0=%d, x1=%d, y1=%d\n", pad.c_str(), x0, y0, x1, y1);
    if (x0 > x1 || y0 > y1) return 0;

    int sum = 0;

    int bad = 0;
    int good = 0;
    for (int i = x0; i <= x1; ++i) {
        for (int j = y0; j <= y1; ++j) {
            if (board[i][j] == 1) {
                ++bad;

                bool hori = !was_hori;
                for (int k = y0; k < j; ++k) {
                    if (board[i][k] > 0) hori = false;
                }
                for (int k = j+1; k <= y1; ++k) {
                    if (board[i][k] == 2) hori = false;
                }

                if (hori) {
                    // printf("%s    hori @ (%d, %d)\n", pad.c_str(), i, j);
                    sum += daq(board, x0, y0, i-1, y1, true, d+1) *
                           daq(board, i+1, y0, x1, y1, true, d+1);
                }

                bool vert = was_hori;
                for (int k = x0; k < i; ++k) {
                    if (board[k][j] > 0) vert = false;
                }
                for (int k = i+1; k <= x1; ++k) {
                    if (board[k][j] == 2) vert = false;
                }

                if (vert) {
                    // printf("%s    vert @ (%d, %d)\n", pad.c_str(), i, j);
                    sum += daq(board, x0, y0, x1, j-1, false, d+1) *
                           daq(board, x0, j+1, x1, y1, false, d+1);
                }

            } else if (board[i][j] == 2) {
                ++good;
            }
        }
    }

    if (bad == 0 && good == 1) {
        assert(sum == 0);
        sum = 1;
    }
    // printf("%sreturn=%d\n", pad.c_str(), sum);
    return sum;
}

int main() {
    int N; cin >> N;
    vector<vector<int>> board(20, vector<int>(20));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> board[i][j];
        }
    }
    // end of input.

    int res = daq(board, 0, 0, N-1, N-1, false, 0);
    res += daq(board, 0, 0, N-1, N-1, true, 0);
    cout << (res > 0 ? res : -1) << endl;

    return 0;
}

