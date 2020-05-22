#include "bits/stdc++.h"
using namespace std;

int main() {
    int n; cin >> n;
    int sz = sqrt(n) + 1;
    vector<bool> isprime(sz, true);
    vector<int> primes;

    for (int i = 2; i < sz; ++i) {
        if (isprime[i]) {
            for (int j = 2; i*j < sz; ++j) {
                isprime[i*j] = false;
            }
            primes.push_back(i);
        }
    }

    int res = n-1;
    for (const auto p : primes) {
        if (n % p == 0) {
            res = n - n/p;
            break;
        }
    }
    cout << res << endl;
    return 0;
}