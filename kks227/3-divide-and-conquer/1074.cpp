#include "bits/stdc++.h"
using namespace std;

int daq(int x0, int y0, int d, int x, int y) {
    if (d == 1) return 1;
    else if (x < x0+d/2 && y < y0+d/2) {
        return daq(x0, y0, d/2, x, y);
    }
    else if (x < x0+d/2 && y0+d/2 <= y) {
        return (daq(x0, y0+d/2, d/2, x, y) + (d/2)*(d/2));
    }
    else if (x0+d/2 <= x && y < y0+d/2) {
        return (daq(x0+d/2, y0, d/2, x, y) + (d/2)*(d/2)*2);
    }
    else {
        return (daq(x0+d/2, y0+d/2, d/2, x, y) + (d/2)*(d/2)*3);
    }
}

int main() {
    int n, x, y; cin >> n >> x >> y;
    cout << daq(0, 0, pow(2, n), x, y) - 1 << endl;
}