#include "bits/stdc++.h"
using namespace std;

void solve()
{
    int N;
    cin >> N;

    int mid;
    priority_queue<int, vector<int>, less<int>> le_pq;
    priority_queue<int, vector<int>, greater<int>> gt_pq;
    cin >> mid;

    vector<int> res{mid};
    for (int i = 2; i <= N; ++i) {
        int x;
        cin >> x;
        if (x <= mid) {
            le_pq.push(x);
        } else {
            gt_pq.push(x);
        }
        if (i % 2 == 1) {
            if (le_pq.size() > gt_pq.size()) {
                gt_pq.push(mid);
                mid = le_pq.top();
                le_pq.pop();
            } else if (le_pq.size() < gt_pq.size()) {
                le_pq.push(mid);
                mid = gt_pq.top();
                gt_pq.pop();
            }
            res.push_back(mid);
        }
    }

    cout << res.size() << "\n";
    for (int i = 0; i < res.size(); i += 10) {
        for (int j = i; j < min((int)res.size(), i + 10); ++j) {
            cout << res[j] << ' ';
        }
        cout << "\n";
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