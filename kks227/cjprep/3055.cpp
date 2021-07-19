#include "bits/stdc++.h"
using namespace std;
using pii = pair<int, int>;

enum Cell
{
    kNull = 0,
    kGoal,
    kSonic,
    kWater,
    kInvalid,
    kCellMax
};

enum SonicStatus
{
    kContinue = 0,
    kSuccess,
    kDied,
    kSonicStatusMax
};

void run_water(vector<vector<Cell>>* map, queue<pii>* waters)
{
    queue<pii> tmp_q;

    auto is = [&](Cell c, int i, int j) {
        return map->at(i).at(j) == c;
    };

    auto add_water = [&](int i, int j) {
        if (0 <= i && i < map->size() && 0 <= j && j < map->at(0).size() && !is(kWater, i, j) && !is(kInvalid, i, j)
            && !is(kGoal, i, j)) {
            tmp_q.emplace(i, j);
            map->at(i).at(j) = kWater;
        }
    };

    while (!waters->empty()) {
        auto w = waters->front();
        waters->pop();
        add_water(w.first - 1, w.second);
        add_water(w.first + 1, w.second);
        add_water(w.first, w.second - 1);
        add_water(w.first, w.second + 1);
    }
    swap(*waters, tmp_q);
}

SonicStatus run_sonic(vector<vector<Cell>>* map, queue<pii>* sonics)
{
    queue<pii> tmp_q;

    auto is = [&](Cell c, int i, int j) {
      return map->at(i).at(j) == c;
    };
    auto add_sonic = [&](int i, int j) {
        if (!is(kWater, i, j) && !is(kSonic, i, j) && !is(kInvalid, i, j)) {
            if (is(kGoal, i, j)) {
                return true;
            }
            tmp_q.emplace(i, j);
            map->at(i).at(j) = kSonic;
        }
        return false;
    };

    while (!sonics->empty()) {
        auto s = sonics->front();
        sonics->pop();
        if (0 < s.first) {
            if (add_sonic(s.first - 1, s.second)) {
                return kSuccess;
            }
        }
        if (s.first + 1 < map->size()) {
            if (add_sonic(s.first + 1, s.second)) {
                return kSuccess;
            }
        }
        if (0 < s.second) {
            if (add_sonic(s.first, s.second - 1)) {
                return kSuccess;
            }
        }
        if (s.second + 1 < map->at(0).size()) {
            if (add_sonic(s.first, s.second + 1)) {
                return kSuccess;
            }
        }
    }
    if (tmp_q.empty()) {
        return kDied;
    } else {
        swap(*sonics, tmp_q);
        return kContinue;
    }
}

int main()
{
    int R, C;
    cin >> R >> C;
    vector<vector<Cell>> map(R, vector<Cell>(C, kNull));
    queue<pii> waters;
    queue<pii> sonics;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            char c;
            cin >> c;
            if (c == 'D') {
                map[i][j] = kGoal;
            } else if (c == 'S') {
                map[i][j] = kSonic;
                sonics.emplace(i, j);
            } else if (c == '*') {
                map[i][j] = kWater;
                waters.emplace(i, j);
            } else if (c == 'X') {
                map[i][j] = kInvalid;
            }
        }
    }

    const auto print_map = [&]() {
        for (const auto& row : map) {
            for (const auto& c : row) {
                cout << c << ' ';
            }
            cout << endl;
        }
        cout << endl;
    };

    for (int cnt = 1;; ++cnt) {
        run_water(&map, &waters);
        const auto status = run_sonic(&map, &sonics);
        if (status == kSuccess) {
            cout << cnt << endl;
            return EXIT_SUCCESS;
        } else if (status == kDied) {
            cout << "KAKTUS" << endl;
            return EXIT_SUCCESS;
        }
    }

    return EXIT_FAILURE;
}