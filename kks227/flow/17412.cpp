#include "bits/stdc++.h"
using namespace std;

struct Edge {
    int to, cap, flow;
    Edge* dual;
    Edge(int t, int c) : to(t), cap(c), flow(0), dual(nullptr) {}
    void add(int f) {
        flow += f;
        dual->flow -= f;
    }
    int spare() const { return cap - flow; }
};

int main() {
    int N, M;
    cin >> N >> M;

    const int src = 1;
    const int sink = 2;
    const int size = N + 1;
    vector<vector<unique_ptr<Edge>>> graph(size);

    while (M--) {
        int from, to;
        cin >> from >> to;

        graph[from].push_back(make_unique<Edge>(to, 1));
        graph[to].push_back(make_unique<Edge>(from, 0));
        graph[from].back()->dual = graph[to].back().get();
        graph[to].back()->dual = graph[from].back().get();
    }

    int res = 0;
    while (true) {
        vector<int> prev(size, -1);
        vector<Edge*> edges(size, nullptr);
        queue<int> q;
        q.push(src);

        while (!q.empty() && prev[sink] == -1) {
            const auto cur = q.front();
            q.pop();

            for (const auto& e : graph[cur]) {
                const auto next = e->to;
                if (prev[next] == -1 && e->spare() > 0) {
                    q.push(next);
                    prev[next] = cur;
                    edges[next] = e.get();
                    if (next == sink) {
                        break;
                    }
                }
            }
        }
        if (prev[sink] == -1) {
            break;
        }

        static constexpr int kMax = INT_MAX / 2;
        int flow = kMax;
        for (int cur = sink; cur != src; cur = prev[cur]) {
            flow = min(flow, edges[cur]->spare());
        }
        for (int cur = sink; cur != src; cur = prev[cur]) {
            edges[cur]->add(flow);
        }
        res += flow;
    }

    cout << res << endl;
    return 0;
}
