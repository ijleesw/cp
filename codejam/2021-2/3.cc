#include "bits/stdc++.h"
using namespace std;

struct plll {
    long first, second, third;
};

static constexpr long kMod = 1e9 + 7;

plll GCD(const long a, const long b) {
    if (a == 0) {
        return {b, 0, 1};
    }
    const auto [gcd, x, y] = GCD(b % a, a);
    return {gcd, y - (b / a) * x, x};
}

long inverse(const long n, const long m) {
    const auto [gcd, x, y] = GCD(n, m);
    return (x % m + m) % m;
}

long DFS(vector<long>& subtree_sz, const vector<unordered_set<long>>& graph, const long cur) {
    long res = 0;
    for (const auto child : graph[cur]) {
        res += DFS(subtree_sz, graph, child);
    }
    return subtree_sz[cur] = res + 1;
}

long solve() {
    long N;
    cin >> N;
    vector<long> arr(N + 1, 0);
    for (long i = 1; i <= N; ++i) {
        cin >> arr[i];
    }

    vector<unordered_set<long>> childs(N + 1);
    vector<long> parent(N + 1, 0);
    long cur = 0;
    for (long i = 1; i <= N; ++i) {
        if (arr[i] > arr[i - 1] + 1) {  // invalid input
            return 0;
        }

        if (arr[i] == arr[i - 1] + 1) {
            childs[cur].insert(i);
            parent[i] = cur;
            cur = i;

        } else {
            const auto back = arr[i - 1] + 1 - arr[i];
            int last = cur;
            for (int j = 0; j < back; ++j) {
                last = cur;
                cur = parent[cur];
            }
            
            childs[cur].erase(last);
            childs[cur].insert(i);
            parent[i] = cur;

            childs[i].insert(last);
            parent[last] = cur;

            cur = i;
        }

        //cout << endl;
        //for (int i = 0; i <= N; ++i) {
        //    cout << i << ": ";
        //    for (const auto c : childs[i]) {
        //        cout << c << ' ';
        //    }
        //    cout << endl;
        //}
        //for (int i = 0; i <= N; ++i) {
        //    cout << parent[i] << endl;
        //}
    }

    vector<long> subtree_sz(N + 1, 0);
    DFS(subtree_sz, childs, 0);

    long res = 1;
    for (long i = 1; i <= N; ++i) {
        res = (res * i) % kMod;
    }
    for (long i = 1; i <= N; ++i) {
        const auto inv = inverse(subtree_sz[i], kMod);
        res = (res * inv) % kMod;
    }
    return res;
}

int main()
{
    long T;
    cin >> T;
    for (long t = 1; t <= T; ++t) {
        cout << "Case #" << t << ": " << solve() << endl;
    }

    return 0;
}
