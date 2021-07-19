#include "bits/stdc++.h"
using namespace std;

int find(vector<int>& uf, int x)
{
    if (uf[x] < 0) {
        return x;
    } else {
        return uf[x] = find(uf, uf[x]);
    }
}

void merge(vector<int>& uf, int x, int y)
{
    const auto rt_x = find(uf, x);
    const auto rt_y = find(uf, y);
    if (rt_x != rt_y) {
        uf[rt_x] = rt_y;
    }
}

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> uf(N, -1);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int x;
            cin >> x;
            if (x == 1) {
                merge(uf, i, j);
            }
        }
    }

    int first;
    cin >> first;
    --first;
    for (int i = 1; i < M; ++i) {
        int next;
        cin >> next;
        --next;
        if (find(uf, first) != find(uf, next)) {
            cout << "NO\n";
            return EXIT_SUCCESS;
        }
    }
    cout << "YES\n";
    return EXIT_SUCCESS;
}