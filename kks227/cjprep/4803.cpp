#include "bits/stdc++.h"
using namespace std;

class Solver
{
public:
    Solver(int t, int v, int e) : t_(t), v_(v), e_(e), tree_(v), visited_(v, false), treeCnt_(0), isCurTree_(0) {}

    void getInput()
    {
        for (int i = 0; i < e_; ++i) {
            int a, b;
            cin >> a >> b;
            --a;
            --b;
            tree_[a].push_back(b);
            tree_[b].push_back(a);
        }
    }

    void solve()
    {
        for (int i = 0; i < v_; ++i) {
            if (visited_[i]) {
                continue;
            }
            isCurTree_ = true;
            DFS(i, -1);
            if (isCurTree_) {
                ++treeCnt_;
            }
        }

        if (treeCnt_ == 0) {
            cout << "Case " << t_ << ": No trees.\n";
        } else if (treeCnt_ == 1) {
            cout << "Case " << t_ << ": There is one tree.\n";
        } else {
            cout << "Case " << t_ << ": A forest of " << treeCnt_ << " trees.\n";
        }
    }

private:
    void DFS(const int cur, const int parent)
    {
        if (visited_[cur]) {
            return;
        }
        visited_[cur] = true;

        for (const auto child : tree_[cur]) {
            if (visited_[child]) {
                if (child != parent) {
                    isCurTree_ = false;
                }
                continue;
            }

            DFS(child, cur);
        }
    }

    int t_;
    int v_;
    int e_;
    vector<vector<int>> tree_;
    vector<bool> visited_;
    int treeCnt_;
    bool isCurTree_;

};

int main()
{
    for (int T = 1; ; ++T) {
        int a, b;
        cin >> a >> b;
        if (a == 0 && b == 0) {
            break;
        }
        Solver s(T, a, b);
        s.getInput();
        s.solve();
    }

    return EXIT_SUCCESS;
}