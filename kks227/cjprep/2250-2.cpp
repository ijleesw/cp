#include "bits/stdc++.h"
using namespace std;
using pii = pair<int, int>;

void DFS(vector<pii>& values, int& order, const vector<pii>& tree, const int cur, const int level)
{
    if (tree[cur].first != -1) {
        DFS(values, order, tree, tree[cur].first, level + 1);
    }
    values[level].first = min(values[level].first, order);
    values[level].second = max(values[level].second, order);
    ++order;
    if (tree[cur].second != -1) {
        DFS(values, order, tree, tree[cur].second, level + 1);
    }
}

int main()
{
    int N;
    cin >> N;
    vector<pii> tree(N + 1);
    vector<int> parent(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        int p, c1, c2;
        cin >> p >> c1 >> c2;
        tree[p].first = c1;
        tree[p].second = c2;
        if (c1 != -1) {
            parent[c1] = p;
        }
        if (c2 != -1) {
            parent[c2] = p;
        }
    }
    const int root = find(begin(parent) + 1, end(parent), 0) - begin(parent);

    int order = 0;
    vector<pii> values(N + 1, std::make_pair(INT_MAX / 3, INT_MIN / 3));
    DFS(values, order, tree, root, 1);

    int max_lvl = 1;
    int max_val = -1;
    for (int i = 1; i < values.size(); ++i) {
        const auto& val = values[i];
        const auto cur_val = val.second - val.first + 1;
        if (cur_val > max_val) {
            max_val = cur_val;
            max_lvl = i;
        }
    }
    cout << max_lvl << ' ' << max_val << endl;

    return EXIT_SUCCESS;
}