#include "bits/stdc++.h"
using namespace std;


int dist(int x, int y) {
    return abs(x) + abs(y);
}

string solve() {
    int x, y; cin >> x >> y;
    string path; cin >> path;

    if (x == 0 && y == 0) {
        return "0";
    }
    // now x, y != 0, 0

    int min_dist = INT_MAX;
    int cur_time = 0;

    for (const auto d : path) {
        ++cur_time;
        if (d == 'N') ++y;
        if (d == 'S') --y;
        if (d == 'E') ++x;
        if (d == 'W') --x;

        if (dist(x, y) <= cur_time) {
            min_dist = min(min_dist, max(cur_time, dist(x, y)));
        }
    }

    if (min_dist == INT_MAX) return "IMPOSSIBLE";
    else return to_string(min_dist);
}

int main() {
    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        printf("Case #%d: %s\n", t, solve().c_str());
    }
    return 0;
}
