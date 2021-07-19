#include "bits/stdc++.h"
using namespace std;

class Solver
{
public:
    Solver(int N) : N_(N), tree_(N + 1), visited_(N + 1, false), parent_(N + 1, 0) {}

    void getInput() {
        for (int i = 0; i < N_ - 1; ++i) {
            int a, b;
            cin >> a >> b;
            tree_[a].push_back(b);
            tree_[b].push_back(a);
        }
    }

    void DFS(const int cur) {
        if (visited_[cur]) {
            return;
        }
        visited_[cur] = true;
        for (const auto child : tree_[cur]) {
            if (!visited_[child]) {
                parent_[child] = cur;
                DFS(child);
            }
        }
    }

    void print() {
        for (int i = 2; i <= N_; ++i) {
            cout << parent_[i] << "\n";
        }
    }

private:
    int N_;
    vector<vector<int>> tree_;
    vector<bool> visited_;
    vector<int> parent_;
};

int main()
{
    int N;
    cin >> N;

    Solver s{N};
    s.getInput();
    s.DFS(1);
    s.print();

    return EXIT_SUCCESS;
}