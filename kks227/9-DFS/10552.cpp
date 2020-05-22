#include "bits/stdc++.h"
using namespace std;

int main() {
    int N, M, P; cin >> N >> M >> P;

    unordered_map<int, int> fav;
    unordered_map<int, int> hate;

    for (int i = 0; i < N; ++i) {
        int f, h; cin >> f >> h;
        fav[i] = (f);
        if (hate.find(h) == end(hate)) hate[h] = i;
    }

    vector<bool> visited(M+1, false);
    int cur = P;
    int cnt = 0;

    while (!visited[cur]) {
        visited[cur] = true;
        const auto it = hate.find(cur);
        if (it == end(hate)) {
            cout << cnt << endl;
            return 0;

        } else {
            cur = fav[it->second];
            ++cnt;
        }
    }

    cout << -1 << endl;
    return 0;
}