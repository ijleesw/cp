#include "bits/stdc++.h"
using namespace std;
using pii = pair<int, int>;

// first: self included
// second: self non-included
pii DFS(vector<bool>& visited, const vector<vector<int>>& tree, const int cur)
{
    visited[cur] = true;
    int incl = 1;
    int nonincl = 0;
    for (const auto child : tree[cur]) {
        if (!visited[child]) {
            auto [child_incl, child_nonincl] = DFS(visited, tree, child);
            incl += min(child_incl, child_nonincl);
            nonincl += child_incl;
        }
    }
    return {incl, nonincl};
}

int main()
{
    int N;
    cin >> N;
    vector<vector<int>> tree(N);
    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        --a, --b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    // end of input

    vector<bool> visited(N, false);
    const auto res = DFS(visited, tree, 0);
    cout << min(res.first, res.second) << endl;

    return EXIT_SUCCESS;
}