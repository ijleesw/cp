#include "bits/stdc++.h"
using namespace std;

using pii = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    vector<pii> xs;
    vector<pii> ys;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        xs.emplace_back(x, i);
        ys.emplace_back(y, i);
    }

    // reorder
    sort(begin(xs), end(xs));
    sort(begin(ys), end(ys));

    vector<int> xss(n);
    vector<int> yss(n);
    for (int i = 0; i < 2; ++i) {
        auto& ss = i == 0 ? xss : yss;
        auto& s = i == 0 ? xs : ys;

        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (i == 0 || s[i].first == s[i - 1].first) {
                ss[s[i].second] = cnt;
            } else {
                ss[s[i].second] = ++cnt;
            }
        }
    }

    vector<vector<int>> sum2d(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < n; ++i) {
        sum2d[xss[i] + 1][yss[i] + 1] = 1;
    }
    for (int i = 1; i < n + 1; ++i) {
        for (int j = 1; j < n + 1; ++j) {
            sum2d[i][j] += sum2d[i - 1][j] + sum2d[i][j - 1] - sum2d[i - 1][j - 1];
        }
    }

    auto res = numeric_limits<int>::max();
    for (int i = 1; i < n + 1; ++i) {
        for (int j = 1; j < n + 1; ++j) {
            int ll = sum2d[i][j];
            int lr = sum2d[i].back() - sum2d[i][j];
            int ul = sum2d.back()[j] - sum2d[i][j];
            int ur = sum2d.back().back() - sum2d.back()[j] - sum2d[i].back() + sum2d[i][j];
            res = min(res, max(max(ll, lr), max(ul, ur)));
        }
    }
    cout << res << endl;
    return 0;
}