#include "bits/stdc++.h"
using namespace std;

int main() {
    int x; cin >> x;

    int cur_step = 1;

    while (x > cur_step) {
        x -= cur_step;
        ++cur_step;
    }

    // step이 짝수면 위에서 아래, 홀수면 아래에서 위
    // step만큼 값이 나온다.

    int a, b;
    if (cur_step % 2 == 0) {
        a = x, b = (cur_step + 1 - x);
    } else {
        a = (cur_step + 1 - x), b = x;
    }
    cout << a << '/' << b << endl;

    return 0;
}