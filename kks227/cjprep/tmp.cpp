#include "bits/stdc++.h"
using namespace std;

int get_router_cnt(const vector<int>& coords, const int dist)
{
    int cnt = 1;
    int last_pos = coords[0];

    for (int i = 1; i < coords.size(); ++i) {
        if (coords[i] - last_pos < dist) {
            continue;
        }
        ++cnt;
        last_pos = coords[i];
    }

    return cnt;
}

int main()
{
    int house_cnt, router_cnt;
    cin >> house_cnt >> router_cnt;
    vector<int> house_coords(house_cnt);
    for (int i = 0; i < house_cnt; ++i) {
        cin >> house_coords[i];
    }
    sort(begin(house_coords), end(house_coords));

    int l = 1;
    int r = 1000000000;
    int res = -1;
    while (l <= r) {
        int m = (l + r) / 2;
        const auto cur_cnt = get_router_cnt(house_coords, m);

        if (cur_cnt < router_cnt) {
            r = m - 1;
        } else if (cur_cnt >= router_cnt) {
            res = m;
            l = m + 1;
        }
    }
    assert(res != -1);

    cout << res << endl;

    return 0;
}