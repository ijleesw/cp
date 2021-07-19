#include "bits/stdc++.h"
using namespace std;

static const int kInvalidCnt = std::numeric_limits<int>::max();

template <typename Matx>
void apply(Matx& board, int curpos, int len, int val)
{

    int x = curpos / 10;
    int y = curpos % 10;
    for (int i = x; i < x + len; ++i) {
        for (int j = y; j < y + len; ++j) {
            board[i][j] = val;
        }
    }
}

template <typename Matx>
bool isApplicable(const Matx& board, int curpos, int len)
{
    int x = curpos / 10;
    int y = curpos % 10;
    if (x + len > 10 || y + len > 10) {
        return false;
    }
    for (int i = x; i < x + len; ++i) {
        for (int j = y; j < y + len; ++j) {
            if (board[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}

template <typename Matx>
int DFS(Matx& board, vector<int>& papercnt, int curpos)
{
    int x = curpos / 10;
    int y = curpos % 10;
    if (curpos == 100) {
        return 0;
    }
    if (board[x][y] == 0) {
        return DFS(board, papercnt, curpos + 1);
    }
    int min_res = kInvalidCnt;
    for (int len = 1; len <= 5; ++len) {
        if (papercnt[len] < 5 && isApplicable(board, curpos, len)) {
            apply(board, curpos, len, 0);
            ++papercnt[len];
            min_res = min(min_res, DFS(board, papercnt, curpos + 1));
            --papercnt[len];
            apply(board, curpos, len, 1);
        }
    }
    return min_res == kInvalidCnt ? kInvalidCnt : min_res + 1;
}

int main()
{
    vector<vector<int>> board(10, vector<int>(10));
    for (int i = 0; i < 100; ++i) {
        cin >> board[i / 10][i % 10];
    }
    vector<int> papercnt(6, 0);

    const auto res = DFS(board, papercnt, 0);
    cout << (res == kInvalidCnt ? -1 : res) << endl;

    return EXIT_SUCCESS;
}
