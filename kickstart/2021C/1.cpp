#include "bits/stdc++.h"
using namespace std;

static constexpr long kMod = 1e9 + 7;

long countTo(const char* s, const int pos, const int sz, const int K, const vector<long>& cache) { // same case not included
    if (pos >= sz) {
        return 0;
    }
    long res = s[pos] - 'a';
    res = (res * cache[sz - pos - 1]) % kMod;
    return (res + countTo(s, pos + 1, sz, K, cache)) % kMod;
}

long solve() {
    int N, K;
    char S[100002]{};
    scanf("%d %d\n", &N, &K);
    scanf("%s", S);

    vector<long> cache(N + 2);
    cache[0] = 1;
    for (int i = 1; i < cache.size(); ++i) {
        cache[i] = (cache[i - 1] * K) % kMod;
    }

    const int sz = strlen(S);
    const int half_pos = (sz + 1) / 2;

    long res = countTo(S, 0, half_pos, K, cache);

    bool can_add = false;
    for (int i = half_pos; i < sz; ++i) {
        const int rev_pos = sz - 1 - i;
        if (S[rev_pos] < S[i]) {
            can_add = true;
            break;
        } else if (S[rev_pos] > S[i]) {
            break;
        }
    }

    return (res + static_cast<int>(can_add)) % kMod;
}

int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cout << "Case #" << t << ": " << solve() << endl;
    }

    return 0;
}
