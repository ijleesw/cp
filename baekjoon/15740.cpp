#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    string A, B; cin >> A >> B;

    vector<int> as, bs, cs;
    if (A[0] == '-') {
        for (int i = A.size() - 1; i >= 1; --i) as.push_back(-1 * (A[i] - '0'));
    } else {
        for (int i = A.size() - 1; i >= 0; --i) as.push_back(A[i] - '0');
    }
    if (B[0] == '-') {
        for (int i = B.size() - 1; i >= 1; --i) bs.push_back(-1 * (B[i] - '0'));
    } else {
        for (int i = B.size() - 1; i >= 0; --i) bs.push_back(B[i] - '0');
    }

    int as_sz = as.size();
    int bs_sz = bs.size();
    if (as_sz < bs_sz) {
        for (int i = 0; i < bs_sz - as_sz; ++i) as.push_back(0);
    } else {
        for (int i = 0; i < as_sz - bs_sz; ++i) bs.push_back(0);
    }

    assert(as.size() == bs.size());
    for (int i = 0; i < as.size(); ++i) cs.push_back(as[i] + bs[i]);

    for (int i = 0; i < cs.size() - 1; ++i) {
        if (cs[i] < 0) {
            int bor = (-cs[i] + 9) / 10;
            cs[i] += bor * 10;
            cs[i+1] -= bor;
        }
        cs[i+1] += cs[i]/10;
        cs[i] %= 10;
    }

    while (!cs.empty() && cs.back() == 0) cs.pop_back();
    if (cs.empty()) cs.push_back(0);

    if (cs.back() < 0) {
        for (int i = 0; i < cs.size() - 1; ++i) {
            if (cs[i] > 0) {
                cs[i] -= 10;
                cs[i + 1] += 1;
            }
        }
        while (!cs.empty() && cs.back() == 0) cs.pop_back();
    }

    if (cs.back() < 0) cout << '-';
    for (int i = cs.size() - 1; i >= 0; --i) cout << abs(cs[i]);
    cout << endl;

    return 0;
}