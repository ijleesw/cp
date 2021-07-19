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

void solve() {
    int N, M;
    cin >> N >> M;

    int sum = 0;
    vector<vector<int>> board(N, vector<int>(M));
    for (auto& row : board) {
        for (auto& n : row) {
            scanf("%d", &n);
            sum += n;
        }
    }

    const auto encode = [&](int x, int y) {
        return 1 + x * M + y;
    };

    const int src = 0;
    const int sink = 1 + encode(N - 1, M - 1);
    const int size = sink + 1;
    Graph graph(size);

    static constexpr int xd[4] = {0, 0, -1, 1};
    static constexpr int yd[4] = {-1, 1, 0, 0};

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            const auto cur = encode(i, j);

            if ((i + j) % 2 == 0) {
                addEdge(graph, src, cur, board[i][j], 0);

                for (int k = 0; k < 4; ++k) {
                    const auto ni = i + xd[k];
                    const auto nj = j + yd[k];
                    if (0 <= ni && ni < N && 0 <= nj && nj < M) {
                        const auto nbd = encode(ni, nj);
                        addEdge(graph, cur, nbd, kMax, 0);
                    }
                }

            } else {
                addEdge(graph, cur, sink, board[i][j], 0);
            }

        }
    }

    const auto max_flow = maxFlow(graph, src, sink);
    cout << sum - max_flow << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
