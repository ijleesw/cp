#include "bits/stdc++.h"
using namespace std;

int main()
{
    long K;
    cin >> K;

    vector<long> fib{0, 1};
    vector<long> fibsum{0, 1};
    while (fibsum.back() < K) {
        const int sz = fib.size();
        fib.push_back(fib[sz - 1] + fib[sz - 2]);
        fibsum.push_back(fibsum.back() + fib.back());
    }

    string res;
    while (K > 0) {
        --K;
        const auto upper_it = upper_bound(begin(fibsum), end(fibsum), K);
        const int digit = upper_it - begin(fibsum);
        if (res.empty()) {
            res = string(digit, '0');
        }
        res[digit - 1] = '1';
        K -= *prev(upper_it);
    }
    reverse(begin(res), end(res));
    cout << res << endl;

    return EXIT_SUCCESS;
}
