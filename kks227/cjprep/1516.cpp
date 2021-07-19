#include "bits/stdc++.h"
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> time(N, 0);
    vector<int> indegree(N, 0);
    vector<int> reach_time(N, 0);
    vector<vector<int>> graph(N);

    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;
        time[i] = x;
        while (cin >> x) {
            if (x == -1) {
                break;
            }
            ++indegree[i];
            graph[x - 1].push_back(i);
        }
    }

    queue<int> q;
    for (int i = 0; i < N; ++i) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        const auto cur = q.front();
        q.pop();

        for (const auto child : graph[cur]) {
            reach_time[child] = max(reach_time[child], reach_time[cur] + time[cur]);
            if (--indegree[child] == 0) {
                q.push(child);
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << reach_time[i] + time[i] << endl;
    }

    return EXIT_SUCCESS;
}
