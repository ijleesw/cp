#include <bits/stdc++.h>
using namespace std;

static constexpr int kMax = INT_MAX / 2;
static constexpr int kSrc = 0;
static constexpr int kSink = 25;

struct Edge
{
    int to, cap, flow;
    Edge* dual;
    Edge(int t, int c) : to(t), cap(c), flow(0), dual(nullptr) {}
    void add(int f) {
        flow += f;
        dual->flow -= f;
    }
};

int toIdx(char c) {
    return c <= 'Z' ? c - 'A' : c - 'a' + 26;
}

int main() {
    int N;
    cin >> N;

    vector<vector<unique_ptr<Edge>>> graph(52);
    while (N--) {
        char from, to;
        int c;
        cin >> from >> to >> c;
        const int f = toIdx(from);
        const int t = toIdx(to);

        graph[f].push_back(make_unique<Edge>(t, c));
        graph[t].push_back(make_unique<Edge>(f, c));
        graph[f].back()->dual = graph[t].back().get();
        graph[t].back()->dual = graph[f].back().get();
    }

    int res = 0;
    while (true) {
        vector<int> prev(52, -1);
        vector<Edge*> edges(52, nullptr);
        queue<int> q;
        q.push(kSrc);

        while (!q.empty() && prev[kSink] == -1) {
            const auto cur = q.front();
            q.pop();

            for (const auto& e : graph[cur]) {
                if (prev[e->to] == -1 && e->cap > e->flow) {
                    q.push(e->to);
                    prev[e->to] = cur;
                    edges[e->to] = e.get();
                    if (e->to == kSink) {
                        break;
                    }
                }
            }
        }
        if (prev[kSink] == -1) {
            break;
        }

        int flow = kMax;
        for (int cur = kSink; cur != kSrc; cur = prev[cur]) {
            const auto e = edges[cur];
            flow = min(flow, e->cap - e->flow);
        }
        for (int cur = kSink; cur != kSrc; cur = prev[cur]) {
            const auto e = edges[cur];
            e->add(flow);
        }
        res += flow;
    }

    cout << res << endl;
    return 0;
}
