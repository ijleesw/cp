#include "bits/stdc++.h"
using namespace std;
using pii = pair<int, int>;

bool PiiCmp(const pii& lhs, const pii& rhs) {
    return lhs.first < rhs.first;
}

int main() {
    int n; cin >> n;
    vector<int> start(n);
    vector<int> finish(n);

    for (int i = 0; i < n; ++i) cin >> start[i] >> finish[i];
    sort(begin(start), end(start));
    sort(begin(finish), end(finish));

    int start_idx = 0;
    int finish_idx = 0;
    int cnt = 0, max_cnt = 0;

    for (int i = 0; i < n; ++i) {   // index of finish
        while (start_idx < n && start[start_idx] < finish[i]) {
            ++start_idx, ++cnt;
        }
        max_cnt = max(max_cnt, cnt);
        --cnt;
    }

    cout << max_cnt << endl;

    return 0;
}