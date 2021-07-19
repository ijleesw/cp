#include "bits/stdc++.h"
using namespace std;

int find(vector<int>& uf, const int x)
{
    if (uf[x] < 0) {
        return x;
    } else {
        return uf[x] = find(uf, uf[x]);
    }
}

void merge(vector<int>& uf, const int x, const int y)
{
    const auto rt_x = find(uf, x);
    const auto rt_y = find(uf, y);
    if (rt_x == rt_y) {
        return;
    }
    if (uf[rt_x] > uf[rt_y]) {  // x is cheaper
        uf[rt_y] = rt_x;
    } else {
        uf[rt_x] = rt_y;
    }
}

int main()
{
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> money(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> money[i];
        money[i] *= -1;
    }
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        merge(money, a, b);
    }

    int sum = 0;
    for (int i = 1; i <= N; ++i) {
        if (money[i] < 0) {
            // cout << i << ", " << money[i] << endl;
            sum -= money[i];
        }
    }
    if (sum <= K) {
        cout << sum << endl;
    } else {
        cout << "Oh no" << endl;
    }
    return EXIT_SUCCESS;
}
