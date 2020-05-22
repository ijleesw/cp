#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while (T--)
    {
        int n; cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i]; --v[i];
        }

//        for (auto e : v) std::cout << e << ' '; std::cout << std::endl;

        vector<bool> visited(n, false);
        unordered_set<int> us;

        int teamed = 0;

        for (int i = 0; i < n; ++i) {
            if (visited[i]) continue;

            us.clear();

            int cur = i;
            while (!visited[cur] && us.find(cur) == end(us)) {
                us.insert(cur);
                cur = v[cur];
            }

            if (visited[cur]) {
                for (auto e : us) visited[e] = true;
                continue;
            }

            int head = cur;
            int cycle_size = 1;
            while ((cur = v[cur]) != head) ++cycle_size;

//            printf("i=%d, cycle_size=%d\n", i, cycle_size);

            teamed += cycle_size;

            for (auto e : us) visited[e] = true;
        }

        std::cout << n - teamed << std::endl;
    }

    return 0;
}