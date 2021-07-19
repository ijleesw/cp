#include "bits/stdc++.h"
using namespace std;

static constexpr int kMax = INT_MAX / 2;

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

using Graph = vector<vector<unique_ptr<Edge>>>;

void addEdge(Graph& graph, int from, int to, int fwd_cap, int bwd_cap) {
    graph[from].push_back(make_unique<Edge>(to, fwd_cap));
    graph[to].push_back(make_unique<Edge>(from, bwd_cap));
    graph[from].back()->dual = graph[to].back().get();
    graph[to].back()->dual = graph[from].back().get();
}

int maxFlow(Graph& graph, const int src, const int sink) {
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

        int flow = kMax;
        for (int cur = sink; cur != src; cur = prev[cur]) {
            flow = min(flow, edges[cur]->spare());
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
    cin >> M >> N;
    // man : 1~N
    // pig : N + 1 ~ N + M
    // src : 0
    // sink: N + M + 1

    const int src = 0;
    const int sink = N + M + 1;
    const int sz = sink + 1;
    Graph graph(sz);

    const int man_offset = 0;
    const int pig_offset = N;

    for (int i = 1; i <= M; ++i) {
        int n;
        cin >> n;
        addEdge(graph, i + pig_offset, sink, n, 0);
    }

    for (int i = 1; i <= N; ++i) {
        int a, b;
        cin >> a;
        while (a--) {
            int n;
            cin >> n;
            addEdge(graph, i + man_offset, n + pig_offset, kMax, 0);
        }
        cin >> b;
        addEdge(graph, src, i + man_offset, b, 0);
    }

    for (int i = 1; i <= M; ++i) {
        for (int j = i + 1; j <= M; ++j) {
            addEdge(graph, i + pig_offset, j + pig_offset, kMax, kMax);
        }
    }

    cout << maxFlow(graph, src, sink) << endl;
    return 0;
}
