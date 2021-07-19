#include "bits/stdc++.h"
using namespace std;

static constexpr int kUnvisited = -1;

struct Elt
{
    int x;
    int y;
    int civil;
};

int find(vector<int>& uf, const int x)
{
    if (uf[x] < 0) {
        return x;
    } else {
        return uf[x] = find(uf, uf[x]);
    }
}

bool merge(vector<int>& uf, const int x, const int y)
{
    const auto rt_x = find(uf, x);
    const auto rt_y = find(uf, y);
    if (rt_x == rt_y) {
        return false;
    } else {
        uf[rt_x] = rt_y;
        return true;
    }
}

int BFS(vector<vector<int>>& board, vector<int>& uf, queue<Elt>& q)
{
    const int N = board.size();
    const int K = uf.size();

    const auto is_valid = [N](const auto x, const auto y) {
      return 0 <= x && x < N && 0 <= y && y < N;
    };

    static constexpr int xdiff[4] = {-1, 1, 0, 0};
    static constexpr int ydiff[4] = {0, 0, -1, 1};

    int rem_civil = K;

    auto q_cp = q;
    while (!q_cp.empty()) {
        const auto elt = q_cp.front();
        q_cp.pop();
        for (int i = 0; i < 4; ++i) {
            const int x = elt.x + xdiff[i];
            const int y = elt.y + ydiff[i];
            if (!is_valid(x, y)) {
                continue;
            }
            if (board[x][y] != kUnvisited) {
                const auto merged = merge(uf, elt.civil, board[x][y]);
                if (merged) {
                    --rem_civil;
                }
            }
        }
    }
    if (rem_civil == 1) {
        return 0;
    }

    int year = 0;
    while (!q.empty()) {
        ++year;
        queue<Elt> child_q;
        while (!q.empty()) {
            const auto elt = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                const int x = elt.x + xdiff[i];
                const int y = elt.y + ydiff[i];
                if (!is_valid(x, y)) {
                    continue;
                }
                if (board[x][y] != kUnvisited) {
                    const auto merged = merge(uf, elt.civil, board[x][y]);
                    if (merged) {
                        --rem_civil;
                    }
                } else {
                    board[x][y] = elt.civil;
                    child_q.push({x, y, elt.civil});
                }
                for (int j = 0; j < 4; ++j) {
                    const int _x = x + xdiff[i];
                    const int _y = y + ydiff[i];
                    if (is_valid(_x, _y) && board[_x][_y] != kUnvisited) {
                        if (merge(uf, elt.civil, board[_x][_y])) {
                            --rem_civil;
                        }
                    }
                }
            }
        }
        if (rem_civil == 1) {
            return year;
        }
        swap(q, child_q);
    }
    return -1;
}

int main()
{
    int N, K;
    cin >> N >> K;
    vector<vector<int>> board(N, vector<int>(N, kUnvisited));

    queue<Elt> q;
    for (int i = 0; i < K; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        --x;
        --y;
        q.push({x, y, i});
        board[x][y] = i;
    }

    vector<int> uf(K, -1);
    cout << BFS(board, uf, q) << endl;

    return EXIT_SUCCESS;
}