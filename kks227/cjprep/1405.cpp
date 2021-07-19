#include "bits/stdc++.h"
using namespace std;

// https://stackoverflow.com/a/15161029
namespace std {
template <>
struct hash<std::pair<int, int>> {
    inline size_t operator()(const std::pair<int, int> &v) const {
        std::hash<int> int_hasher;
        return int_hasher(v.first) ^ int_hasher(v.second);
    }
};
}

unordered_set<pair<int, int>> visited;
double prob = 1;
double E, W, S, N;

void DFS(const pair<int, int>& curpos, const double curprob, const int rem)
{
    if (visited.find(curpos) != visited.end()) {
        prob -= curprob;
        return;
    }

    visited.emplace(curpos);
    if (E > 0 && rem > 0) {
        DFS(make_pair(curpos.first + 1, curpos.second), curprob * E, rem - 1);
    }
    if (W > 0 && rem > 0) {
        DFS(make_pair(curpos.first - 1, curpos.second), curprob * W, rem - 1);
    }
    if (S > 0 && rem > 0) {
        DFS(make_pair(curpos.first, curpos.second - 1), curprob * S, rem - 1);
    }
    if (N > 0 && rem > 0) {
        DFS(make_pair(curpos.first, curpos.second + 1), curprob * N, rem - 1);
    }
    visited.erase(visited.find(curpos));
}

int main()
{
    int cnt;
    cin >> cnt;
    cin >> E >> W >> S >> N;
    E /= 100;
    W /= 100;
    S /= 100;
    N /= 100;

    DFS(make_pair(0, 0), 1, cnt);
    cout << fixed << setprecision(20) << prob << endl;

    return EXIT_SUCCESS;
}
