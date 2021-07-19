#include <bits/stdc++.h>
using namespace std;

static constexpr int kMax = INT_MAX / 2;

int main()
{
    int N;
    cin >> N;

    vector<vector<int>> cap(52, vector<int>(52, 0));
    vector<vector<int>> flow(52, vector<int>(52, 0));
    vector<vector<int>> graph(52);

    while (N--) {
        char from, to;
        int c;
        cin >> from >> to >> c;
        from -= (from <= 'Z' ? 'A' : 'a' - 26);
        to -= (to <= 'Z' ? 'A' : 'a' - 26);

        cap[to][from] = cap[from][to] += c;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    int res = 0;
    while (true) {
        const int src = 0;
        const int sink = 25;

        vector<int> prev(52, -1);
        queue<int> q;
        q.push(src);

        while (!q.empty() && prev[sink] == -1) {
            const auto cur = q.front();
            q.pop();

            for (const auto next : graph[cur]) {
                if (prev[next] == -1 && cap[cur][next] - flow[cur][next] > 0) {
                    q.push(next);
                    prev[next] = cur;
                    if (next == sink) {
                        break;
                    }
                }
            }
        }
        if (prev[sink] == -1) {
            break;
        }

        int f = kMax;
        for (int cur = sink; cur != src; cur = prev[cur]) {
            const auto p = prev[cur];
            f = min(f, cap[p][cur] - flow[p][cur]);
        }
        for (int cur = sink; cur != src; cur = prev[cur]) {
            const auto p = prev[cur];
            flow[p][cur] += f;
            flow[cur][p] -= f;
        }
        res += f;
    }

    cout << res << endl;
    return 0;
}
