#include "bits/stdc++.h"
using namespace std;

int T, N;

void solve() {
    char buf[256]{};

    for (int i = 1; i < N; ++i) {
        printf("M %d %d\n", i, N);
        fflush(stdout);

        scanf("%s", buf);

        const int idx = atoi(buf);
        if (idx != i) {
            printf("S %d %d\n", min(i, idx), max(i, idx));
            fflush(stdout);
            scanf("%s", buf);
        }
    }

    printf("D\n");
    fflush(stdout);
    scanf("%s", buf);
}

int main()
{
    char buf[256]{};
    scanf("%s", buf);
    T = atoi(buf);
    scanf("%s", buf);
    N = atoi(buf);

    for (int t = 0; t < T; ++t) {
        solve();
    }

    return 0;
}
