#include "bits/stdc++.h"
using namespace std;

bool IsValid(int c, int n, int s, int b) {
    int c1 = c/100, c2 = c/10%10, c3=c%10;
    int n1 = n/100, n2 = n/10%10, n3=n%10;

    if (c1 == c2 || c1 == c3 || c2 == c3) return false;
    if (c1 == 0 || c2 == 0 || c3 == 0) return false;

    if (c1 == n1) --s;
    else if (c1 == n2 || c1 == n3) --b;

    if (c2 == n2) --s;
    else if (c2 == n1 || c2 == n3) --b;

    if (c3 == n3) --s;
    else if (c3 == n1 || c3 == n2) --b;

    return (s == 0 && b == 0);
}

int main() {
    vector<bool> valid(1000, true);

    int n; cin >> n;
    while (n--) {
        int n, s, b; cin >> n >> s >> b;
        for (int i = 100; i <= 999; ++i) {
            if (valid[i]) valid[i] = IsValid(i, n, s, b);
        }
    }

    int cnt = 0;
    for (int i = 100; i <= 999; ++i) cnt += (int)valid[i];
    cout << cnt << endl;

    return 0;
}