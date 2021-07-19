#include "bits/stdc++.h"
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> incr;
    for (int i = 0; i < N; ++i) {
        int x;
        scanf("%d", &x);
        const auto it = lower_bound(begin(incr), end(incr), x);
        if (it == end(incr)) {
            incr.push_back(x);
        } else {
            *it = x;
        }
    }
    cout << N - incr.size() << endl;

    return EXIT_SUCCESS;
}