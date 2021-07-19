#include "bits/stdc++.h"
using namespace std;

template <typename MAP>
long calc(MAP&& cache, const long N, const long P, const long Q)
{
    if (N == 0) {
        return 1;
    }
    long sum = 0;
    for (const auto n : {N / P, N / Q}) {
        const auto it = cache.find(n);
        if (it == end(cache)) {
            const auto res = calc(cache, n, P, Q);
            cache[n] = res;
            sum += res;
        } else {
            sum += it->second;
        }
    }
    return sum;
}

int main()
{
    long N, P, Q;
    cin >> N >> P >> Q;
    unordered_map<long, long> cache;
    cout << calc(cache, N, P, Q) << endl;

    return EXIT_SUCCESS;
}