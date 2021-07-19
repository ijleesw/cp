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

template <typename G>
void addEdge(G&& graph, int from, int to, int fwd_cap, int bwd_cap) {
    graph[from].push_back(make_unique<Edge>(to, fwd_cap));
    graph[to].push_back(make_unique<Edge>(from, bwd_cap));
    graph[from].back()->dual = graph[to].back().get();
    graph[to].back()->dual = graph[from].back().get();
}

int main() {
    int N, M;
    cin >> N >> M;

    const int src = 1 * 2 + 1;
    const int sink = 2 * 2;
    const int size = 2 * (N + 1);
    vector<vector<unique_ptr<Edge>>> graph(size);

    for (int i = 1; i <= N; ++i) {
        addEdge(graph, i * 2, i * 2 + 1, 1, 0);
    }

    while (M--) {
        int from, to;
        cin >> from >> to;
        addEdge(graph, from * 2 + 1, to * 2, 1, 0);
        addEdge(graph, to * 2 + 1, from * 2, 1, 0);
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

        int flow = INT_MAX / 2;
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
