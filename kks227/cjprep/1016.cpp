#include "bits/stdc++.h"
using namespace std;

int main()
{
    size_t m, M;
    cin >> m >> M;
    size_t upper = sqrt(M) + 1;

    vector<bool> visited(upper + 1, false);
    vector<size_t> primes;
    for (int i = 2; i <= upper; ++i) {
        if (!visited[i]) {
            primes.push_back(i);
            for (int j = i; j <= upper; j += i) {
                visited[j] = true;
            }
        }
    }

    visited = vector<bool>(M - m + 1, false);
    for (const size_t p : primes) {
        const size_t pp = p * p;
        for (size_t i = (m + pp - 1) / pp * pp; i <= M; i += pp) {
            visited[i - m] = true;
        }
    }
    cout << count(begin(visited), end(visited), false) << endl;

    return 0;
}
