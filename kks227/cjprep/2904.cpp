#include "bits/stdc++.h"
using namespace std;

vector<int> get_primes(const int n)
{
    vector<int> res;
    vector<bool> visited(n, false);
    for (int i = 2; i < n; ++i) {
        if (!visited[i]) {
            res.push_back(i);
            for (int j = i; j < n; j += i) {
                visited[j] = true;
            }
        }
    }
    return res;
}

int main()
{
    int N;
    cin >> N;
    vector<int> ns(N);
    for (auto& n : ns) {
        cin >> n;
    }

    vector<int> primes = get_primes(1000001);
    const int P = primes.size();
    vector<vector<int>> exps(N, vector<int>(P, 0));

    vector<int> gcd_cnt(P, 0);
    vector<int> wildcards(P, 0);

    for (int i = 0; i < N; ++i) {
        auto n = ns[i];
        auto& cur_exp = exps[i];
        for (int j = 0; j < P; ++j) {
            const auto p = primes[j];
            while (n % p == 0) {
                n /= p;
                ++cur_exp[j];
            }
        }
        assert(n == 1 && "factorization failed");
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < P; ++j) {
            gcd_cnt[j] += exps[i][j];
        }
    }
    for (int i = 0; i < P; ++i) {
        wildcards[i] = gcd_cnt[i] % N;
        gcd_cnt[i] /= N;
    }

    int cnt = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < P; ++j) {
            if (exps[i][j] > gcd_cnt[j] && wildcards[j] > 0) {
                const int cur_diff = exps[i][j] - gcd_cnt[j];
                if (cur_diff <= wildcards[j]) {
                    wildcards[j] -= cur_diff;
                } else {
                    cnt += cur_diff - wildcards[j];
                    wildcards[j] = 0;
                }
            } else {
                cnt += abs(exps[i][j] - gcd_cnt[j]);
            }
        }
    }
    assert(cnt % 2 == 0 && "gcd fac. count failed");

    size_t gcd = 1;
    for (int i = 0; i < P; ++i) {
        gcd *= pow(primes[i], gcd_cnt[i]);
    }
    cout << gcd << ' ' << cnt / 2 << endl;

    return 0;
}
