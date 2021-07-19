#include "bits/stdc++.h"
using namespace std;
using pii = pair<int, int>;

pii DFS(const vector<vector<pii>>& tree, const int cur)
{
    vector<pii> childWts(max(tree[cur].size(), 2lu), {0, 0});
    for (int i = 0; i < tree[cur].size(); ++i) {
        const auto& child = tree[cur][i];
        childWts[i] = DFS(tree, child.first);
        childWts[i].second += child.second;
    }

    partial_sort(begin(childWts), begin(childWts) + 2, end(childWts), [](const auto& lhs, const auto& rhs) {
      return lhs.second > rhs.second;
    });
    const auto max_depth = childWts[0].second;
    const auto sec_depth = childWts[1].second;

    partial_sort(begin(childWts), begin(childWts) + 2, end(childWts), [](const auto& lhs, const auto& rhs) {
        return lhs.first > rhs.first;
    });
    const auto max_len = max(max_depth + sec_depth, childWts[0].first);
    return {max_len, max_depth};
}

int main()
{
    int N;
    cin >> N;
    vector<vector<pii>> tree(N + 1);
    for (int i = 0; i < N - 1; ++i) {
        int from, to, wt;
        cin >> from >> to >> wt;
        tree[from].emplace_back(to, wt);
    }

    cout << DFS(tree, 1).first << endl;

    return EXIT_SUCCESS;
}