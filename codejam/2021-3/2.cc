#include "bits/stdc++.h"
using namespace std;

void print(const vector<vector<int>>& board) {
    for (const auto& row : board) {
        for (const auto& cell : row) {
            cout << (cell == 0 ? '/' : '\\');
        }
        cout << endl;
    }
}

bool isSquare(const vector<vector<int>>& board, const int x, const int y, const int half) {
    bool res = true;
    for (int i = 0; i < half && res; ++i) {
        res = res && (board[x + i][y + half - 1 - i] == 0);
        res = res && (board[x + i][y + half + i] == 1);
        res = res && (board[x + half + i][y + half + half - 1 - i] == 0);
        res = res && (board[x + half + i][y + i] == 1);
    }
    return res;
}

bool check(const vector<vector<int>>& board) {
    const int R = board.size();
    const int C = board[0].size();
    for (int sz = 2; sz <= min(R, C); sz += 2) {
        const int half = sz / 2;

        for (int x = 0; x + sz <= R; ++x) {
            for (int y = 0; y + sz <= C; ++y) {
                if (isSquare(board, x, y, half)) {
                    return false;
                }
            }
        }
    }
    return true;
}

bool BT(vector<vector<int>>& board, vector<int>& Rs, vector<int>& Cs, const int pos) {
    const int R = board.size();
    const int C = board[0].size();

    if (pos > 0) {
        const int px = (pos - 1) / C;
        const int py = (pos - 1) % C;
        for (int sz = 2; sz <= min(px, py) + 1; sz += 2) {
            if (isSquare(board, px - sz + 1, py - sz + 1, sz / 2)) {
                return false;
            }
        }
    }

    if (pos >= R*C) {
        //if (check(board)) {
        //    cout << "POSSIBLE" << endl;
        //    print(board);
        //    return true;
        //} else {
        //    return false;
        //}

        cout << "POSSIBLE" << endl;
        print(board);
        return true;
    }

    const int x = pos / C;
    const int y = pos % C;

    if (Rs[x] > 0 && Cs[y] > 0) {
        board[x][y] = 0;
        --Rs[x], --Cs[y];
        if (BT(board, Rs, Cs, pos + 1)) {
            return true;
        }
        ++Rs[x], ++Cs[y];
    }
    if (C - y > Rs[x] && R - x > Cs[y]) {
        board[x][y] = 1;
        if (BT(board, Rs, Cs, pos + 1)) {
            return true;
        }
    }
    return false;
}

void solve() {
    int R, C;
    cin >> R >> C;
    vector<int> Rs(R), Cs(C);
    for (auto& r : Rs) {
        cin >> r;
    }
    for (auto& c : Cs) {
        cin >> c;
    }

    vector<vector<int>> board(R, vector<int>(C));
    
    if (!BT(board, Rs, Cs, 0)) {
        cout << "IMPOSSIBLE" << endl;
    }
}

int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cout << "Case #" << t << ": ";
        solve();
    }

    return 0;
}
