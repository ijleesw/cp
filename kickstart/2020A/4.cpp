#include "bits/stdc++.h"
using namespace std;

vector<int> Handle(const vector<int>& v) {
    priority_queue<int, vector<int>, greater<int>> pq;

    vector<int> res;
    for (auto e : v) {
        pq.push(e);
        int h = 0;
        while (!pq.empty()) {
            h = max(h, min((int)pq.size(), pq.top()));
            if (pq.top() < pq.size()) pq.pop();
            else break;
        }
        res.push_back(h);
    }
    return res;
}

int main() {
    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        int N; cin >> N;

        vector<int> v(N);
        for (int i = 0; i < N; ++i) cin >> v[i];

        auto res = Handle(v);

        printf("Case #%d: ", t);
        for (auto e : res) printf("%d ", e);
        printf("\n");
    }
    return 0;
}
