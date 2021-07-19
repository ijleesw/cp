#include "bits/stdc++.h"
using namespace std;

int main()
{
    string s;
    cin >> s;
    int l = -1;
    for (int r = 0; r < s.size(); ++r) {
        if (l == -1) {
            s[++l] = s[r];
        } else if (abs(s[l] - s[r]) == 'a' - 'A') {
            --l;
        } else {
            s[++l] = s[r];
        }
    }
    s.resize(l + 1);
    cout << s << endl;
    return 0;
}
