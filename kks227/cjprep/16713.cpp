#include "bits/stdc++.h"
using namespace std;

int main()
{
    int N;
    int M;
    scanf("%d %d", &N, &M);
    vector<int> prefixXor(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
        scanf("%d", &prefixXor[i]);
        prefixXor[i] ^= prefixXor[i - 1];
    }

    int res = 0;
    for (int i = 0; i < M; ++i) {
        int s, e;
        scanf("%d %d", &s, &e);
        res ^= (prefixXor[e] ^ prefixXor[s - 1]);   // s, e : 1-based index
    }
    printf("%d\n", res);

    return EXIT_SUCCESS;
}