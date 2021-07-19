#include "bits/stdc++.h"
using namespace std;

long DFS(const vector<vector<int>>& tree, const vector<long>& wolf, const vector<long>& sheep, const int cur)
{
    long sum = 0;
    for (const auto child : tree[cur]) {
        sum += DFS(tree, wolf, sheep, child);
    }
    sum += sheep[cur];
    sum -= wolf[cur];
    return max(0L, sum);
}

int main()
{
    int N;
    cin >> N;
    vector<vector<int>> tree(N + 1);
    vector<long> wolf(N + 1, 0);
    vector<long> sheep(N + 1, 0);
    for (int i = 2; i <= N; ++i) {
        char c;
        int cnt, parent;
        cin >> c >> cnt >> parent;
        tree[parent].push_back(i);
        if (c == 'S') {
            sheep[i] = cnt;
        } else {
            wolf[i] = cnt;
        }
    }
    cout << DFS(tree, wolf, sheep, 1) << endl;

    return EXIT_SUCCESS;
}