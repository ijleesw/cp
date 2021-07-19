#include "bits/stdc++.h"
using namespace std;

using area_t = size_t;
using height_t = size_t;
using psh = pair<size_t, height_t>;

int main()
{
    int N;
    cin >> N;

    vector<psh> sticks(N);
    for (int i = 0; i < N; ++i) {
        cin >> sticks[i].first >> sticks[i].second;
    }
    sort(begin(sticks), end(sticks));

    size_t l = 0;
    size_t r = N - 1;
    area_t area = 0;
    height_t left_h = 0;
    height_t right_h = 0;

    while (l < r) {
        left_h = max(left_h, sticks[l].second);
        right_h = max(right_h, sticks[r].second);
        if (left_h < right_h) {
            area += left_h * (sticks[l + 1].first - sticks[l].first);
            ++l;
        } else {
            area += right_h * (sticks[r].first - sticks[r - 1].first);
            --r;
        }
    }
    area += sticks[l].second;

    cout << area << endl;
    return 0;
}