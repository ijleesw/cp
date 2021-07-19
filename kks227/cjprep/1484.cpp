#include "bits/stdc++.h"
using namespace std;

int idx2val(int i)
{
    return i * 2 + 1;
}

int main()
{
    int G;
    cin >> G;

    int l = 0;
    int r = 0;
    int sum = 0;
    bool found = false;

    while (true) {
        if (sum > G) {
            sum -= idx2val(l++);
        } else {    // sum <= G
            if (idx2val(r) > G) {
                break;
            } else {
                sum += idx2val(r++);
            }
        }
        if (sum == G && r * r != G) {
            cout << r << endl;
            found = true;
        }
    }

    if (!found) {
        cout << -1 << endl;
    }

    return EXIT_SUCCESS;
}
