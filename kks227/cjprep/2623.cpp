#include "bits/stdc++.h"
using namespace std;

int N, M;

int main()
{
    cin >> N >> M;

    vector<vector<int>> graph(N);
    vector<int> indegree(N, 0);
    for (int i = 0; i < M; ++i) {
        int x;
        cin >> x;
        vector<int> v;
        while (x--) {
            int y;
            cin >> y;
            v.push_back(y - 1);
        }
        for (int i = 1; i < v.size(); ++i) {
            graph[v[i - 1]].push_back(v[i]);
            ++indegree[v[i]];
        }
    }

    queue<int> q;
    for (int i = 0; i < N; ++i) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> res;
    while (!q.empty()) {
        const int cur = q.front();
        q.pop();
        res.push_back(cur);
        
        for (const auto child : graph[cur]) {
            if (--indegree[child] == 0) {
                q.push(child);
            }
        }
    }

    if (res.size() != N) {
        cout << 0 << endl;
    } else {
        for (const auto x : res) {
            cout << x + 1 << endl;
        }
    }

    return EXIT_SUCCESS;
}
