#include "bits/stdc++.h"
using namespace std;

struct Status
{
    int incl;
    int excl;
    vector<int> incls;
    vector<int> excls;
};

Status DFS(vector<bool>& visited, const vector<vector<int>>& graph, const vector<int>& wt, const int cur)
{
    visited[cur] = true;
    Status res = {wt[cur], 0, {cur}, {}};
    for (const auto child : graph[cur]) {
        if (!visited[child]) {
            auto child_s = DFS(visited, graph, wt, child);
            res.incl += child_s.excl;
            move(begin(child_s.excls), end(child_s.excls), back_inserter(res.incls));
            if (child_s.excl > child_s.incl) {
                res.excl += child_s.excl;
                move(begin(child_s.excls), end(child_s.excls), back_inserter(res.excls));
            } else {
                res.excl += child_s.incl;
                move(begin(child_s.incls), end(child_s.incls), back_inserter(res.excls));
            }
        }
    }
    return res;
}

int main()
{
    int N;
    cin >> N;
    vector<int> wt(N);
    for (auto& w : wt) {
        cin >> w;
    }
    vector<vector<int>> graph(N);
    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<bool> visited(N, false);
    auto res = DFS(visited, graph, wt, 0);

    int reswt;
    vector<int> resvec;
    if (res.incl > res.excl) {
        reswt = res.incl;
        resvec = move(res.incls);
    } else {
        reswt = res.excl;
        resvec = move(res.excls);
    }
    sort(begin(resvec), end(resvec));
    cout << reswt << endl;
    for (const auto n : resvec) {
        cout << n + 1 << ' ';
    }
    cout << endl;

    return EXIT_SUCCESS;
}