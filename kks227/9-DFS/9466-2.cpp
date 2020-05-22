#include "bits/stdc++.h"
using namespace std;

void solve()
{
    int N; cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; ++i) {
        int a; cin >> a; v[i] = --a;
    }
    // end of input.

    int cnt = 0;
    vector<int> status(N, -1);

    for (int i = 0; i < N; ++i) {
        int cur = v[i];

        bool finish = false;
        while (!finish) {
            if (status[cur] == -1) {
                status[cur] = i;
                cur = v[cur];
            } else if (status[cur] == i) {
                // cycle detected.
                int tmp = cur;
                do {
                    ++cnt;
                    tmp = v[tmp];
                } while (tmp != cur);
                finish = true;

            } else {    // already visited
                finish = true;
            }
        }
    }

    cout << N - cnt << endl;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
