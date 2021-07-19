#include "bits/stdc++.h"
using namespace std;

void solve()
{
    int _, N, M;
    cin >> N >> M;

    vector<int> indegree(N, 0);
    vector<int> order(N, 1);
    vector<int> order_cnt(N, 0);
    vector<int> final_order(N, 0);
    vector<vector<int>> graph(N);

    for (int i = 0; i < M; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        --a, --b;
        graph[a].push_back(b);
        ++indegree[b];
    }

    queue<int> q;
    for (int i = 0; i < N; ++i) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        const int cur = q.front();
        q.pop();
        if (order_cnt[cur] > 1) {
            final_order[cur] = order[cur] + 1;
        } else {
            final_order[cur] = order[cur];
        }
        for (const int child : graph[cur]) {
            if (--indegree[child] == 0) {
                q.push(child);
            }
            if (order[child] < final_order[cur]) {
                order[child] = final_order[cur];
                order_cnt[child] = 1;
            } else if (order[child] == final_order[cur]) {
                ++order_cnt[child];
            }
        }
    }

    cout << *max_element(begin(final_order), end(final_order)) << endl;
}

int main()
{
    int T;
    cin >> T;
    while (T--) {
        int cnt;
        cin >> cnt;
        cout << cnt << ' ';
        solve();
    }

    return EXIT_SUCCESS;
}
