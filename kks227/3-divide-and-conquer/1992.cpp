#include "bits/stdc++.h"
using namespace std;
using Vec = vector<int>;
using VecVec = vector<vector<int>>;

bool allSame(const VecVec& mm, int x0, int y0, int d) {
    int a = mm[x0][y0];
    for (int i = 0; i < d; ++i) {
        for (int j = 0; j < d; ++j) {
            if (a != mm[x0+i][y0+j]) {
                return false;
            }
        }
    }
    return true;
}

string daq(const VecVec& mm, int x0, int y0, int d) {
    if (d == 1 || allSame(mm, x0, y0, d)) {
        return to_string(mm[x0][y0]);
    }

    string res = "(";
    res += daq(mm, x0, y0, d/2);
    res += daq(mm, x0, y0+d/2, d/2);
    res += daq(mm, x0+d/2, y0, d/2);
    res += daq(mm, x0+d/2, y0+d/2, d/2);
    res += ")";
    return res;
}

int main() {
    int n; cin >> n;
    VecVec mm(n, Vec(n));
    for (int i = 0; i < n; ++i) {
        string line; cin >> line;
        for (int j = 0; j < n; ++j) mm[i][j] = line[j] - '0';
    }
    cout << daq(mm, 0, 0, n) << endl;
    return 0;
}