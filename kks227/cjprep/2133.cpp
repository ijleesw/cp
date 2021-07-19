#include "bits/stdc++.h"
using namespace std;
using pii = pair<int, int>;

struct Status
{
    int x, y, key, step;
};

char maze[50][50]{};
int step[50][50][64];

int main()
{
    memset(step, -1, sizeof(step));

    int N, M;
    cin >> N >> M;
    Status start;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> maze[i][j];
            if (maze[i][j] == '0') {
                start.x = i;
                start.y = j;
                start.key = 0;
                start.step = 0;
            }
        }
    }

    const auto isValid = [N, M](const auto x, const auto y) {
        return 0 <= x && x < N && 0 <= y && y < M;
    };

    queue<Status> bfs;
    bfs.push(start);
    int xdiff[4] = {-1, 1, 0, 0};
    int ydiff[4] = {0, 0, -1, 1};

    while (!bfs.empty()) {
        auto cur = bfs.front();
        bfs.pop();

        for (int i = 0; i < 4; ++i) {
            const auto x = cur.x + xdiff[i];
            const auto y = cur.y + ydiff[i];

            if (isValid(x, y)) {
                const auto m = maze[x][y];

                if (m == '#') {
                    continue;

                } else if (m == '1') {
                    cout << cur.step + 1 << endl;
                    return EXIT_SUCCESS;

                } else if ('a' <= m && m <= 'f') {
                    const auto new_key = cur.key | (1 << (m - 'a'));
                    if (step[x][y][new_key] == -1 || cur.step + 1 < step[x][y][new_key]) {
                        step[x][y][new_key] = cur.step + 1;
                        bfs.push({x, y, cur.key | (1 << (m - 'a')), cur.step + 1});
                    }

                } else if ('A' <= m && m <= 'F') {
                    if (cur.key & (1 << (m - 'A'))) {
                        const auto new_key = cur.key & ~(1 << (m - 'a'));
                        if (step[x][y][new_key] == -1 || cur.step + 1 < step[x][y][new_key]) {
                            step[x][y][new_key] = cur.step + 1;
                            bfs.push({x, y, new_key, cur.step + 1});
                        }
                    }

                } else {
                    if (step[x][y][cur.key] == -1 || cur.step + 1 < step[x][y][cur.key]) {
                        step[x][y][cur.key] = cur.step + 1;
                        bfs.push({x, y, cur.key, cur.step + 1});
                    }
                }
            }
        }
    }
    cout << -1 << endl;
    return EXIT_SUCCESS;
}