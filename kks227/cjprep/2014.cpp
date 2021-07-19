#include "bits/stdc++.h"
using namespace std;
using pii = pair<int, int>;

int main()
{
    int K, N;
    cin >> K >> N;
    vector<int> primes(K);
    for (auto& p : primes) {
        cin >> p;
    }

    // first: cur val, second : min prime idx
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for (int i = 0; i < K; ++i) {
        pq.emplace(primes[i], i);
    }

    int rem = N;
    while (true) {
        const auto top = pq.top();
        pq.pop();
        if (--rem == 0) {
            cout << top.first << endl;
            break;
        }
        for (int i = top.second; i < K; ++i) {
            const auto new_val = static_cast<long>(top.first) * primes[i];
            if (new_val <= numeric_limits<int>::max()) {
                pq.emplace(top.first * primes[i], i);
            }
        }
    }

    return EXIT_SUCCESS;
}