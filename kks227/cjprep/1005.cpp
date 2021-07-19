#include "bits/stdc++.h"
using namespace std;

void solve()
{
    int N, M;
    cin >> N >> M;
    vector<int> time(N);
    for (int i = 0; i < N; ++i) {
        cin >> time[i];
    }
    vector<int> indegree(N, 0);
    vector<vector<int>> graph(N);
    for (int i = 0; i < M; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        --a, --b;
        graph[a].push_back(b);
        ++indegree[b];
    }
    int D;
    cin >> D;
    --D;

    queue<int> q;
    for (int i = 0; i < N; ++i) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    vector<int> reach_time(N, 0);
    while (!q.empty()) {
        const int cur = q.front();
        q.pop();
        for (const int child : graph[cur]) {
            reach_time[child] = max(reach_time[child], reach_time[cur] + time[cur]);
            if (--indegree[child] == 0) {
                q.push(child);
            }
        }
    }
    cout << time[D] + reach_time[D] << endl;
}

int main()
{
    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return EXIT_SUCCESS;
}
