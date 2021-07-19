#include "bits/stdc++.h"
using namespace std;
using pii = pair<int, int>;

// first: self included, second: self not included
pii DFS(vector<bool>& visited, const vector<vector<int>>& tree, const vector<int>& cnt, const int cur)
{
    visited[cur] = true;
    vector<int> incls{0};
    vector<int> nonincls{0};
    for (const auto child : tree[cur]) {
        if (!visited[child]) {
            const auto res = DFS(visited, tree, cnt, child);
            incls.push_back(res.first);
            nonincls.push_back(res.second);
        }
    }

    const auto max_incl = accumulate(begin(nonincls), end(nonincls), 0) + cnt[cur];
    int max_nonincl = 0;
    for (int i = 0; i < incls.size(); ++i) {
        max_nonincl += max(incls[i], nonincls[i]);
    }
    return {max_incl, max_nonincl};
}

int main()
{
    int N;
    cin >> N;
    vector<int> cnt(N);
    for (auto& c : cnt) {
        cin >> c;
    }
    vector<vector<int>> tree(N);
    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    // end of input

    vector<bool> visited(N, false);
    const auto res = DFS(visited, tree, cnt, 0);
    cout << max(res.first, res.second) << endl;

    return EXIT_SUCCESS;
}