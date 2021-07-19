#include "bits/stdc++.h"
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<int>> graph(N);
    vector<int> indegree(N);
    for (int i = 0; i < M; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        --a, --b;
        graph[a].push_back(b);
        ++indegree[b];
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < N; ++i) {
        if (indegree[i] == 0) {
            pq.push(i);
        }
    }
    while (!pq.empty()) {
        const auto cur = pq.top();
        pq.pop();
        printf("%d ", cur + 1);
        for (const auto child : graph[cur]) {
            if (--indegree[child] == 0) {
                pq.push(child);
            }
        }
    }
    cout << endl;

    return EXIT_SUCCESS;
}
