#include "bits/stdc++.h"
using namespace std;

int main() {
    int n; cin >> n;

    vector<int> v;
    v.reserve(2*n + 10);
    for (int i = 0; i <= n; ++i) v.push_back(i);
    int l = 1;
    int r = n;

    while (l < r) {
        ++l;
        v.push_back(v[l]);
        ++l;
        ++r;
    }

    std::cout << v[l] << std::endl;

    return 0;
}