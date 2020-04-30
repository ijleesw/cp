#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    const int kTry = 1001;

    int A, B; cin >> A >> B;
    cout << A/B << '.';
    A %= B, A *= 10;

    for (int i = 0; i < kTry; ++i) {
        if (A < B) {
            cout << '0';
        }
        else {
            cout << A/B;
            A %= B;
        }
        A *= 10;
    }

    cout << endl;
    return 0;
}