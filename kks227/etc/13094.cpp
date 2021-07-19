// wrong
#include "bits/stdc++.h"
using namespace std;

void solve(int n_switch, int n_bulb, int n_query)
{
    vector<vector<bool>> cand(n_bulb, vector<bool>(n_switch, true));

    while (n_query--) {
        string sw, bu;
        cin >> sw >> bu;

        vector<int> exists;
        vector<int> nonexists;
        for (int i = 0; i < sw.size(); ++i) {
            if (sw[i] == '1') {
                exists.push_back(i);
            } else {
                nonexists.push_back(i);
            }
        }
        for (int i = 0; i < bu.size(); ++i) {
            if (bu[i] == '1') {
                for (auto e : nonexists) {
                    cand[i][e] = false;
                }
            } else {
                for (auto e : exists) {
                    cand[i][e] = false;
                }
            }
        }
    }

    for (const auto& c : cand) {
        int cnt = 0;
        int last_pos = -1;
        for (int i = 0; i < c.size(); ++i) {
            if (c[i]) {
                ++cnt;
                last_pos = i;
            }
        }
        if (cnt != 1) {
            cout << '?';
        }
        else  if (last_pos < 10) {
            cout << last_pos;
        }
        else {
            cout << 'A' + (last_pos - 10);
        }
    }
    cout << endl;
}

int main()
{
    while (true) {
        int n, m, q;
        cin >> n >> m >> q;
        if (n == 0 && m == 0 && q == 0) {
            break;
        } else {
            solve(n, m, q);
        }
    }
    return 0;
}