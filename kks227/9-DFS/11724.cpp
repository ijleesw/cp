#include "bits/stdc++.h"
using namespace std;

int main() {
    int N, M; cin >> N >> M;
    vector<vector<int>> graph(N);
    for (int i = 0; i < M; ++i) {
        int a, b; cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }

    vector<bool> visited(N, false);
    int cnt = 0;

    for (int i = 0; i < N; ++i) {
        if (visited[i]) continue;

        queue<int> q;
        q.push(i);

        while (!q.empty()) {
            int cur = q.front(); q.pop();
            if (visited[cur]) continue;
            visited[cur] = true;
            for (auto child : graph[cur]) {
                if (!visited[child]) q.push(child);
            }
        }
        ++cnt;
    }

    cout << cnt << endl;

    return 0;
}