#include "bits/stdc++.h"
using namespace std;

void printNum(const vector<int>& v)
{
    for (auto e : v) {
        cout << e;
    }
    cout << endl;
}

bool isGood(const vector<int>& v)
{
    for (int len = 1; len <= v.size() / 2; ++len) {
        const int right = v.size();
        const int middle = right - len;
        const int left = middle - len;
        bool all_same = true;
        for (int i = 0; i < len; ++i) {
            all_same &= (v[left + i] == v[middle + i]);
        }
        if (all_same) {
            return false;
        }
    }
    return true;
}

bool DFS(vector<int>& v, const int rem)
{
    if (!isGood(v)) {
        return false;
    }
    if (rem == 0) {
        printNum(v);
        return true;
    }
    vector<int> cands;
    switch (v.back()) {
    case 1:
        cands = {2, 3};
        break;
    case 2:
        cands = {1, 3};
        break;
    case 3:
        cands = {1, 2};
        break;
    default:
        break;
    }
    for (const auto c : cands) {
        v.push_back(c);
        if (DFS(v, rem - 1)) {
            return true;
        }
        v.pop_back();
    }
    return false;
}

int main()
{
    int N;
    cin >> N;

    vector<int> v;
    v.push_back(1);
    DFS(v, N - 1);
    return EXIT_SUCCESS;
}
