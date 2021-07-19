#include "bits/stdc++.h"
using namespace std;

struct Node
{
    int left;
    int right;
};

struct NodeInfo
{
    string path;

    bool operator<(const NodeInfo& rhs) const {
        int lhs_sz = path.size();
        int rhs_sz = rhs.path.size();
        int min_sz = min(lhs_sz, rhs_sz);
        for (int i = 0; i < min_sz; ++i) {
            if (path[i] < rhs.path[i]) {
                return true;
            } else if (path[i] > rhs.path[i]) {
                return false;
            }
        }
        if (lhs_sz < rhs_sz) {
            return rhs.path[lhs_sz] == 'R';
        } else if (lhs_sz > rhs_sz) {
            return path[rhs_sz] == 'L';
        } else {
            return false;
        }
    }
};

void DFS(vector<NodeInfo>& nodeInfos, string& path, const vector<Node>& tree, const int cur)
{
    nodeInfos[cur].path = path;

    const auto& curNode = tree[cur];
    if (curNode.left != -1) {
        path.push_back('L');
        DFS(nodeInfos, path, tree, curNode.left);
        path.pop_back();
    }
    if (curNode.right != -1) {
        path.push_back('R');
        DFS(nodeInfos, path, tree, curNode.right);
        path.pop_back();
    }
}

int main()
{
    int N;
    cin >> N;
    vector<Node> tree(N + 1);
    vector<int> parent(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        int p, c1, c2;
        cin >> p >> c1 >> c2;
        tree[p].left = c1;
        tree[p].right = c2;
        if (c1 != -1) {
            parent[c1] = p;
        }
        if (c2 != -1) {
            parent[c2] = p;
        }
    }
    const int root = find(begin(parent) + 1, end(parent), 0) - begin(parent);

    vector<NodeInfo> nodeInfos(N + 1);
    string path;
    DFS(nodeInfos, path, tree, root);
    sort(begin(nodeInfos) + 1, end(nodeInfos));

    vector<int> minIdx(N + 1, INT_MAX / 3);
    vector<int> maxIdx(N + 1, INT_MIN / 3);
    for (int i = 1; i < nodeInfos.size(); ++i) {
        const auto cur_lvl = nodeInfos[i].path.size() + 1;
        minIdx[cur_lvl] = min(minIdx[cur_lvl], i);
        maxIdx[cur_lvl] = max(maxIdx[cur_lvl], i);
    }

    vector<int> width(N + 1);
    for (int i = 0; i < width.size(); ++i) {
        width[i] = maxIdx[i] - minIdx[i] + 1;
    }
    const auto maxPos = max_element(begin(width), end(width));
    cout << maxPos - begin(width) << ' ' << *maxPos << endl;

    return EXIT_SUCCESS;
}