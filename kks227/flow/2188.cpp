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
};

template <typename GRAPH>
void addEdge(GRAPH& graph, int from, int to, int fwd_cap, int bwd_cap) {
    graph[from].push_back(make_unique<Edge>(to, fwd_cap));
    graph[to].push_back(make_unique<Edge>(from, bwd_cap));
    graph[from].back()->dual = graph[to].back().get();
    graph[to].back()->dual = graph[from].back().get();
}

template <typename GRAPH>
int maxFlow(GRAPH& graph, const int src, const int sink) {
    const int N = graph.size();
    int res = 0;

    while (true) {
        vector<int> prev(N, -1);
        vector<Edge*> edges(N, nullptr);
        queue<int> q;
        q.push(src);

        while (!q.empty() && prev[sink] == -1) {
            const auto cur = q.front();
            q.pop();

            for (const auto& e : graph[cur]) {
                const auto next = e->to;
                if (prev[next] == -1 && e->cap > e->flow) {
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
            const auto e = edges[cur];
            flow = min(flow, e->cap - e->flow);
        }
        for (int cur = sink; cur != src; cur = prev[cur]) {
            edges[cur]->add(flow);
        }
        res += flow;
    }
    return res;
}

int main() {
    int N, M;
    cin >> N >> M;

    const int kSrc = 0;
    const int kSink = N + M + 1;

    vector<vector<unique_ptr<Edge>>> graph(kSink + 1);
    for (int i = 1; i <= N; ++i) {
        addEdge(graph, kSrc, i, 1, 0);
    }
    for (int i = 1; i <= N; ++i) {
        int cnt;
        cin >> cnt;
        while (cnt--) {
            int j;
            cin >> j;
            addEdge(graph, i, N + j, 1, 0);
        }
    }
    for (int i = N + 1; i <= N + M; ++i) {
        addEdge(graph, i, kSink, 1, 0);
    }

    cout << maxFlow(graph, kSrc, kSink) << endl;
    return 0;
}
