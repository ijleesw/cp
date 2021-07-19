#include "bits/stdc++.h"
using namespace std;

int d(int n)
{
    int res = n;
    while (n > 0) {
        res += n % 10;
        n /= 10;
    }
    return res;
}

int main()
{
    vector<bool> visited(20000, false);
    for (int i = 1; i <= 10000; ++i) {
        visited[d(i)] = true;
    }
    for (int i = 1; i <= 10000; ++i) {
        if (!visited[i]) {
            printf("%d\n", i);
        }
    }

    return 0;
}
