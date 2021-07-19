#include "bits/stdc++.h"
using namespace std;
using pll = pair<long, long>;

int main()
{
    long N, M;
    cin >> N >> M;
    vector<vector<pll>> graph(N + 1);
    vector<long> min_time(N + 1, 0);
    vector<long> max_time(N + 1, 0);
    vector<long> indegree(N + 1, 0);
    for (long i = 0; i < M; ++i) {
        long a, b, c;
        scanf("%ld %ld %ld", &a, &b, &c);
        graph[a].emplace_back(b, c);
        ++indegree[b];
    }
    long start, goal;
    cin >> start >> goal;

    queue<long> q;
    q.push(start);
    while (!q.empty()) {
        const long cur = q.front();
        q.pop();
        for (const auto child : graph[cur]) {
            const long reach_child = max_time[cur] + child.second;
            min_time[child.first] = min(min_time[child.first], reach_child);
            max_time[child.first] = max(max_time[child.first], reach_child);
            if (--indegree[child.first] == 0) {
                q.push(child.first);
            }
        }
    }

    return 0;
}
