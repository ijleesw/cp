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

using Graph = vector<vector<unique_ptr<Edge>>>;

void addEdge(Graph& graph, int from, int to, int fwd_cap, int bwd_cap) {
    graph[from].push_back(make_unique<Edge>(to, fwd_cap));
    graph[to].push_back(make_unique<Edge>(from, bwd_cap));
    graph[from].back()->dual = graph[to].back().get();
    graph[to].back()->dual = graph[from].back().get();
}

void solve() {
    int N, M;
    cin >> N >> M;

    const int src = 1;
    const int sink = N;
    const int size = N + 1;
    Graph graph(size);

    while (M--) {
        int from, to, cap;
        scanf("%d %d %d", &from, &to, &cap);
        addEdge(graph, from, to, cap, 0);
    }

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
    }

    int res = 0;
    for (auto& es : graph) {
        for (auto& e : es) {
            if (!(e->spare() == 0 && e->cap > 0 && e->flow > 0)) {
                continue;
            }

            const auto from = e->dual->to;
            const auto to = e->to;

            e->cap -= 1;
            e->add(-1);

            vector<int> prev(size, -1);
            queue<int> q;
            q.push(from);
            while (!q.empty() && prev[to] == -1) {
                const auto cur = q.front();
                q.pop();

                for (const auto& e : graph[cur]) {
                    const auto next = e->to;
                    if (prev[next] == -1 && e->spare() > 0) {
                        q.push(next);
                        prev[next] = cur;
                        if (next == to) {
                            break;
                        }
                    }
                }
            }

            if (prev[to] == -1) {
                ++res;
            }

            e->add(1);
            e->cap += 1;
        }
    }
    cout << res << endl;
}

int main() {
    int K;
    cin >> K;
    while (K--) {
        solve();
    }
    return 0;
}
