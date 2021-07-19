#include "bits/stdc++.h"
using namespace std;

int find(vector<int>& v, const int x)
{
    if (v[x] < 0) {
        return x;
    } else {
        return v[x] = find(v, v[x]);
    }
}

int merge(vector<int>& v, const int x, const int y)
{
    const auto rt_x = find(v, x);
    const auto rt_y = find(v, y);
    if (rt_x == rt_y) {
        return -v[rt_x];
    }
    if (v[rt_x] < v[rt_y]) {    // rt_x has larger size
        v[rt_x] += v[rt_y];
        v[rt_y] = rt_x;
        return -v[rt_x];
    } else {
        v[rt_y] += v[rt_x];
        v[rt_x] = rt_y;
        return -v[rt_y];
    }
}

int name2idx(unordered_map<string, int>& nameTable, const string& name)
{
    const auto iter = nameTable.find(name);
    if (iter == end(nameTable)) {
        return nameTable[name] = nameTable.size();
    } else {
        return iter->second;
    }
}

void solve()
{
    int N;
    cin >> N;
    char name1[21]{};
    char name2[21]{};
    unordered_map<string, int> nameTable;
    vector<int> uf; // nonneg: parent idx, neg: -size

    for (int i = 0; i < N; ++i) {
        scanf("%s", name1);
        scanf("%s", name2);
        const auto idx1 = name2idx(nameTable, name1);
        const auto idx2 = name2idx(nameTable, name2);
        if (idx1 >= uf.size()) {
            uf.push_back(-1);
        }
        if (idx2 >= uf.size()) {
            uf.push_back(-1);
        }
        printf("%d\n", merge(uf, idx1, idx2));
    }
}

int main()
{
    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return EXIT_SUCCESS;
}