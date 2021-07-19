#include "bits/stdc++.h"
using namespace std;
using pii = pair<int, int>;

auto compressCoords(const vector<pii>& coords)
{
    map<int, int> xcoordmap;
    map<int, int> ycoordmap;
    for (const auto& coord : coords) {
        xcoordmap[coord.first] = 0;
        ycoordmap[coord.second] = 0;
    }
    int cnt = 0;
    for (auto& xcoord : xcoordmap) {
        xcoord.second = cnt++;
    }
    cnt = 0;
    for (auto& ycoord : ycoordmap) {
        ycoord.second = cnt++;
    }

    vector<pii> compCoords;
    compCoords.reserve(coords.size());
    for (const auto& coord : coords) {
        compCoords.emplace_back(xcoordmap[coord.first], ycoordmap[coord.second]);
    }
    return compCoords;
}

// inclusive (0,0) to exclusive (x,y) : m[x][y] - m[0][0]
auto getPrefixSum(const vector<pii>& coords, const int n_cows)
{
    vector<vector<int>> prefixSum(n_cows + 1, vector<int>(n_cows + 1, 0));
    int coords_idx = 0;
    for (int i = 1; i <= n_cows; ++i) {
        for (int j = 1; j <= n_cows; ++j) {
            if (coords[coords_idx] == std::make_pair(i - 1, j - 1)) {
                prefixSum[i][j] += 1;
                ++coords_idx;
            }
            prefixSum[i][j] += prefixSum[i][j - 1];
            prefixSum[i][j] += prefixSum[i - 1][j];
            prefixSum[i][j] -= prefixSum[i - 1][j - 1];
        }
    }
    return prefixSum;
}

// (x1, y1) to (x2, y2) : inclusive/exclusive
auto getSubSum(const vector<vector<int>>& p, int x1, int y1, int x2, int y2)
{
    return p[x2][y2] - p[x1][y2] - p[x2][y1] + p[x1][y1];
}

auto calcBalancedM(const vector<vector<int>>& prefixSum)
{
    const int n_cows = prefixSum.size() - 1;
    int res = numeric_limits<int>::max();
    for (int i = 0; i <= n_cows; ++i) {
        for (int j = 0; j <= n_cows; ++j) {
            // (i, j) exclusive to lowerleft
            const auto s1 = getSubSum(prefixSum, 0, 0, i, j);
            const auto s2 = getSubSum(prefixSum, i, 0, n_cows, j);
            const auto s3 = getSubSum(prefixSum, 0, j, i, n_cows);
            const auto s4 = getSubSum(prefixSum, i, j, n_cows, n_cows);
            const auto M = max(max(s1, s2), max(s3, s4));
            res = min(res, M);
        }
    }
    return res;
}

int main()
{
    int N;
    cin >> N;
    vector<pii> coords(N);
    for (int i = 0; i < N; ++i) {
        cin >> coords[i].first >> coords[i].second;
    }
    auto compCoords = compressCoords(coords);
    sort(begin(compCoords), end(compCoords));

    auto prefixSum = getPrefixSum(compCoords, N);

    cout << calcBalancedM(prefixSum) << endl;
    return EXIT_SUCCESS;
}