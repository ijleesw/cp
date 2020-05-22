#include "bits/stdc++.h"
using namespace std;

void interact(int n) {
    // send
    printf("%d\n", n);
    fflush(stdout);

    // receive
    char res[256];
    scanf("%s", res);
}

int solve() {
    return 0;
}

int main() {
    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        int res = solve();
        printf("Case #%d: %d\n", t, res);
    }
    return 0;
}
