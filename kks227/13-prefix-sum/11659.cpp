#include "bits/stdc++.h"

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> prefix_sum;
    prefix_sum.reserve(N + 1);
    prefix_sum.push_back(0);

    while (N--) {
        int x; scanf("%d", &x);
        prefix_sum.push_back(x + prefix_sum.back());
    }

    while (M--) {
        int a, b;
        scanf("%d %d", &a, &b);
        std::cout << prefix_sum[b] - prefix_sum[a - 1] << "\n";
    }
    return 0;
}