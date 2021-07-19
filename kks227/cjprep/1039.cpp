#include "bits/stdc++.h"
using namespace std;

int swapDigit(int n, int i, int j)
{
    int i10 = static_cast<int>(pow(10, i));
    int ithVal = n / i10 % 10;
    int j10 = static_cast<int>(pow(10, j));
    int jthVal = n / j10 % 10;
    return n + (ithVal - jthVal) * j10 + (jthVal - ithVal) * i10;
}

int main()
{
    int N, K;
    cin >> N >> K;

    int n_digit = 0;
    int _N = N;
    while (_N > 0) {
        ++n_digit;
        _N /= 10;
    }
    int n_10 = pow(10, n_digit - 1);

    unordered_set<int> from;
    unordered_set<int> to;
    from.insert(N);

    while (!from.empty() && K--) {
        for (auto n : from) {
            for (int i = 0; i < n_digit; ++i) {
                for (int j = i + 1; j < n_digit; ++j) {
                    auto val = swapDigit(n, i, j);
                    if (val >= n_10) {
                        to.insert(val);
                    }
                }
            }
        }
        swap(from, to);
        to.clear();
    }

    if (from.empty()) {
        cout << -1 << endl;
    } else {
        cout << *max_element(begin(from), end(from)) << endl;
    }
    return EXIT_SUCCESS;
}