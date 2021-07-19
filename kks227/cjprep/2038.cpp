#include "bits/stdc++.h"
using namespace std;

int main()
{
    long N;
    cin >> N;

    vector<int> pos{0};
    long cur = 0;
    long stride_pos = 1;
    long val = 1;
    long res = -1;

    while (true) {
        val += stride_pos - 1;
        pos.push_back(val);
        ++cur;
        if (cur == pos[stride_pos]) {
            ++stride_pos;
        }

        if (val <= N) {
            res = cur;
        } else {
            break;
        }
    }
    cout << res << endl;

    return EXIT_SUCCESS;
}
