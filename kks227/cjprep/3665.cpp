#include "bits/stdc++.h"
using namespace std;
using pii = pair<int, int>;

void solve()
{
    int N;
    cin >> N;
    vector<int> order(N);
    for (auto& x : order) {
        cin >> x;
    }
    vector<int> indegree(N + 1, 0);
    vector<unordered_set<int>> graph(N + 1);
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            graph[order[i]].insert(order[j]);
            ++indegree[order[j]];
        }
    }
    int M;
    cin >> M;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        if (graph[a].find(b) != end(graph[a])) {
            graph[a].erase(b);
            graph[b].insert(a);
            --indegree[b];
            ++indegree[a];
        } else if (graph[b].find(a) != end(graph[b])) {
            graph[b].erase(a);
            graph[a].insert(b);
            --indegree[a];
            ++indegree[b];
        } else {
            assert(false);
        }
    }

    queue<int> q;
    for (int i = 1; i <= N; ++i) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    vector<int> res;
    while (!q.empty()) {
        if (q.size() >= 2) {
            puts("?");
            return;
        }
        const auto cur = q.front();
        q.pop();
        res.push_back(cur);
        for (const auto child : graph[cur]) {
            if (--indegree[child] == 0) {
                q.push(child);
            }
        }
    }
    if (res.size() < N) {
        puts("IMPOSSIBLE");
        return;
    }
    for (const auto x : res) {
        cout << x << ' ';
    }
    cout << endl;
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
