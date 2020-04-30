#include "bits/stdc++.h"
using namespace std;
using IntVec = vector<int>;
using IntVecVec = vector<vector<int>>;

bool allSame(const IntVecVec& mm, int xl, int xr, int yl, int yr) {
    int a = mm[xl][yl];
    for (int i = xl; i < xr; ++i) {
        for (int j = yl; j < yr; ++j) {
            if (a != mm[i][j]) return false;
        }
    }
    return true;
}

void daq(const IntVecVec& mm, int xl, int xr, int yl, int yr, int& zero, int& minus, int& plus) {
    if (allSame(mm, xl, xr, yl, yr)) {
        if (mm[xl][yl] == 0) ++zero;
        if (mm[xl][yl] == 1) ++plus;
        if (mm[xl][yl] == -1) ++minus;
    }
    else {
        int xd = (xr - xl) / 3;
        int yd = (yr - yl) / 3;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                daq(mm, xl+xd*i, xl+xd*(i+1), yl+yd*j, yl+yd*(j+1), zero, minus, plus);
            }
        }
    }
}

int main() {
    int n; cin >> n;
    IntVecVec mm(n, IntVec(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) cin >> mm[i][j];
    }

    int zero = 0, minus = 0, plus = 0;
    daq(mm, 0, n, 0, n, zero, minus, plus);
    cout << minus << endl << zero << endl << plus << endl;

    return 0;
}