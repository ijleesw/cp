#include "bits/stdc++.h"

using namespace std;

using IntVec = vector<int>;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<IntVec> matx(n + 1, IntVec(n + 1, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int x;
            scanf("%d", &x);
            matx[i + 1][j + 1] = matx[i][j + 1] + matx[i + 1][j] - matx[i][j] + x;
        }
    }

    while (m--) {
        int a, b, c, d;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        cout << matx[c][d] - matx[a - 1][d] - matx[c][b - 1] + matx[a - 1][b - 1] << "\n";
    }

    return 0;
}