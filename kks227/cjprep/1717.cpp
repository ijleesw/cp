#include "bits/stdc++.h"
using namespace std;

int find(vector<int>& uf, int x)
{
    if (uf[x] < 0) {
        return x;
    }
    return uf[x] = find(uf, uf[x]);
}

void merge(vector<int>& uf, int x, int y)
{
    const auto root_x = find(uf, x);
    const auto root_y = find(uf, y);
    if (root_x < root_y) {
        uf[root_x] += uf[root_y];
        uf[root_y] = root_x;
    } else if (root_x > root_y) {
        uf[root_y] += uf[root_x];
        uf[root_x] = root_y;
    }
}

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> uf(N + 1, -1);  // pos: parent, neg: root & its size

    for (int i = 0; i < M; ++i) {
        int op, a, b;
        scanf("%d %d %d", &op, &a, &b);
        if (op == 0) {
            merge(uf, a, b);
        } else {
            const auto same = find(uf, a) == find(uf, b);
            printf("%s\n", same ? "YES" : "NO");
        }
    }

    return EXIT_SUCCESS;
}