#include "bits/stdc++.h"
using namespace std;

struct Board {
    int cell[3][3];
    int empty_x;
    int empty_y;
    void move(int xdiff, int ydiff) {
        swap(cell[empty_x][empty_y], cell[empty_x + xdiff][empty_y + ydiff]);
    }
};

struct Elt {
    int val;
    int step;
};

int board2Int(const Board& board)
{
    int res = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            res *= 10;
            res += board.cell[i][j];
        }
    }
    return res;
}

Board int2Board(int val)
{
    Board board;
    for (int i = 2; i >= 0; --i) {
        for (int j = 2; j >= 0; --j) {
            board.cell[i][j] = val % 10;
            if (board.cell[i][j] == 0) {
                board.empty_x = i;
                board.empty_y = j;
            }
            val /= 10;
        }
    }
    return board;
}

int main()
{
    Board board;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> board.cell[i][j];
            if (board.cell[i][j] == 0) {
                board.empty_x = i;
                board.empty_y = j;
            }
        }
    }

    queue<Elt> q;
    unordered_set<int> visited;
    q.push({board2Int(board), 0});

    auto isValid = [&](auto b, int xdiff, int ydiff) {
        if (0 <= b.empty_x + xdiff and b.empty_x + xdiff < 3 and 0 <= b.empty_y + ydiff and b.empty_y + ydiff < 3) {
            b.move(xdiff, ydiff);
            return visited.find(board2Int(b)) == visited.end();
        } else {
            return false;
        }
    };

    auto proc = [&](auto b, auto xdiff, auto ydiff, auto step) {
        if (isValid(b, xdiff, ydiff)) {
            b.move(xdiff, ydiff);
            visited.insert(board2Int(b));
            q.push({board2Int(b), step + 1});
        }
    };

    auto print = [](const auto& elt) {
        auto b = int2Board(elt.val);
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                cout << b.cell[i][j] << ' ';
            }
            cout << endl;
        }
        cout << endl;
    };

    while (!q.empty()) {
        auto elt = q.front();
        q.pop();

        // print(elt);

        if (elt.val == 123456780) {
            cout << elt.step << endl;
            return EXIT_SUCCESS;
        }
        auto b = int2Board(elt.val);
        proc(b, -1, 0, elt.step);
        proc(b, 1, 0, elt.step);
        proc(b, 0, -1, elt.step);
        proc(b, 0, 1, elt.step);
    }
    cout << -1 << endl;
    return EXIT_SUCCESS;
}