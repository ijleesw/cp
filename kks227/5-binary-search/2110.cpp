#include "bits/stdc++.h"
using namespace std;

int main() {
    int n, c; cin >> n >> c;
    vector<int> pos(n);
    for (int i = 0; i < n; ++i) cin >> pos[i];
    //end of input

    sort(begin(pos), end(pos));

    if (c == 2) {
        cout << pos.back() - pos.front() << endl;
        return 0;
    }
    // now c >= 3

    int l = 1;
    int r = pos.back() - pos.front();
    int res = 1;

    while (l <= r) {
        int m = (l + r) / 2;
        // every dist >= m

        int rem_dist = m;
        int ins_cnt = 0;
        int last_pos = -1;

        for (int i = 1; i < n-1; ++i) {
            if (rem_dist <= pos[i] - pos[i-1]) {
                // install @ pos[i]
                ins_cnt++;
                rem_dist = m;
                last_pos = pos[i];
            } else {    // rem_dist > pos[i] - pos[i-1]
                rem_dist -= (pos[i] - pos[i-1]);
            }
            if (ins_cnt == c - 2) break;
        }

//        printf("m=%d, ins_cnt=%d, last_pos=%d\n", m, ins_cnt, last_pos);

        bool succeeded = (ins_cnt == c - 2 && pos.back() - last_pos >= m);

        if (succeeded) {
            res = m;
            l = m+1;
        } else {
            r = m-1;
        }
    }

    assert(res != -1);
    cout << res << endl;
    return 0;
}
