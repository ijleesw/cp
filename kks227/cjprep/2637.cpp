#include "bits/stdc++.h"
using namespace std;
using pii = pair<int, int>;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<pii>> graph(N + 1);
    vector<int> indegree(N + 1, 0);

    for (int i = 0; i < M; ++i) {
        int from, to, wt;
        cin >> to >> from >> wt;
        graph[from].emplace_back(to, wt);
        ++indegree[to];
    }

    vector<int> base;
    vector<vector<long>> cnt(N + 1, vector<long>(N + 1, 0));
    queue<int> q;
    for (int i = 1; i <= N; ++i) {
        if (indegree[i] == 0) {
            cnt[i][i] = 1;
            base.push_back(i);
            q.push(i);
        }
    }

    while (!q.empty()) {
        const auto cur = q.front();
        q.pop();
        for (const auto child : graph[cur]) {
            for (const auto b : base) {
                cnt[child.first][b] += cnt[cur][b] * child.second;
            }
            if (--indegree[child.first] == 0) {
                q.push(child.first);
            }
        }
    }

    for (const auto b : base) {
        cout << b << ' ' << cnt[N][b] << endl;
    }

    return EXIT_SUCCESS;
}
