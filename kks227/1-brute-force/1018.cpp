#include "bits/stdc++.h"
using namespace std;

int board[51][51];

const int W = 0;
const int B = 1;

int main() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char c; cin >> c;
            if (c == 'W') board[i][j] = W;
            else board[i][j] = B;
        }
    }

    int min_res = INT_MAX;
    for (int I = 0; I < n-7; ++I) {
        for (int J = 0; J < m - 7; ++J) {
            int start_w = 0;
            int start_b = 0;

            for (int i = I; i < I+8; ++i) {
                for (int j = J; j < J+8; ++j) {
                    if ((i + j) % 2 == 0) {
                        start_w += (int) (board[i][j] != W);
                        start_b += (int) (board[i][j] != B);
                    } else {
                        start_w += (int) (board[i][j] != B);
                        start_b += (int) (board[i][j] != W);
                    }
                }
            }

            min_res = min(min_res, min(start_w, start_b));
        }
    }

    cout << min_res << endl;
    return 0;
}