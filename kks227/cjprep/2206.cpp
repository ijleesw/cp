#include "bits/stdc++.h"
using namespace std;

struct Cur
{
    int x;
    int y;
    int step;
    int broken;
};

int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<int>> map(N, vector<int>(M, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            char c;
            cin >> c;
            map[i][j] = c - '0';
        }
    }

    vector<vector<bool>> zero_visited(N, vector<bool>(M, false));
    zero_visited[0][0] = true;
    auto one_visited = zero_visited;

    queue<Cur> q;
    q.push({0, 0, 1, 0});

    auto stepable = [&](const auto& cur, int idiff, int jdiff) {
        const auto target_x = cur.x + idiff;
        const auto target_y = cur.y + jdiff;
        if (0 <= target_x and target_x < N and 0 <= target_y and target_y < M) {
            if (cur.broken == 0) {
                if (map[target_x][target_y] == 0) {
                    return !zero_visited[target_x][target_y];
                } else {
                    return !one_visited[target_x][target_y];
                }
            } else {
                if (map[target_x][target_y] == 1) {
                    return false;
                } else {
                    return !one_visited[target_x][target_y];
                }
            }
        }
        return false;
    };

    auto run_step = [&](const auto& cur, int idiff, int jdiff) {
        if (!stepable(cur, idiff, jdiff)) {
            return;
        }
        const auto target_x = cur.x + idiff;
        const auto target_y = cur.y + jdiff;
        auto newCur = cur;
        newCur.x = target_x;
        newCur.y = target_y;
        ++newCur.step;
        if (map[target_x][target_y] == 1) {
            assert(newCur.broken == 0);
            ++newCur.broken;
        }
        q.push(newCur);
        if (map[target_x][target_y] + cur.broken == 1) {
            one_visited[target_x][target_y] = true;
        } else {
            zero_visited[target_x][target_y] = true;
        }
    };

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        if (cur.x == N - 1 && cur.y == M - 1) {
            cout << cur.step << endl;
            return EXIT_SUCCESS;
        }
        run_step(cur, -1, 0);
        run_step(cur, 1, 0);
        run_step(cur, 0, -1);
        run_step(cur, 0, 1);
    }
    cout << -1 << endl;
    return EXIT_SUCCESS;
}