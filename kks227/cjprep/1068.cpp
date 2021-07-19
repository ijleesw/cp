#include "bits/stdc++.h"
using namespace std;

int DFS(const vector<vector<int>>& tree, const int cur, const int del)
{
    if (cur == del) {
        return 0;
    } else if (tree[cur].empty()) {
        return 1;
    } else {
        int sum = 0;
        for (const auto child : tree[cur]) {
            sum += DFS(tree, child, del);
        }
        return max(1, sum);
    }
}

int main()
{
    int N;
    cin >> N;
    vector<int> parents(N);
    for (auto& p : parents) {
        cin >> p;
    }
    int del;
    cin >> del;

    vector<vector<int>> tree(N);
    int root = -1;
    for (int i = 0; i < N; ++i) {
        if (parents[i] == -1) {
            root = i;
        } else {
            tree[parents[i]].push_back(i);
        }
    }

    cout << DFS(tree, root, del) << endl;

    return EXIT_SUCCESS;
}