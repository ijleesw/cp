#include "bits/stdc++.h"
using namespace std;

int getEndVal(int k, const vector<int>& vals) {
    int res = 0;
    int cur = 0;
    for (int i = 0; i < k; ++i) {
        cur += vals[i % 2];
        res = min(res, cur);
    }
    return res;
}

int getMidVal(int k, char l, char r, int X, int Y) {
    if (l == 'C' && r == 'C' || l == 'J' && r == 'J') {
        return min(0, (k + 1) / 2 * (X + Y));
    } else if (l == 'C' && r == 'J') {
        return X + min(0, k / 2 * (X + Y));
    } else if (l == 'J' && r == 'C') {
        return Y + min(0, k / 2 * (X + Y));
    } else {
        assert(false);
        return 0;
    }
}

int solve() {
    int X, Y;
    string S;
    cin >> X >> Y >> S;
    
    int l = 0;
    int res = 0;
    while (true) {
        while (l < S.size() && S[l] != '?') {
            ++l;
        }
        if (l == S.size()) {
            break;
        }
        // now S[l] == '?'

        int r = l;
        while (r < S.size() && S[r] == '?') {
            ++r;
        }
        // now S[r] != '?'

        if (l == 0 && r == S.size()) {
            res += min(getEndVal(r - l - 1, {X, Y}), getEndVal(r - l - 1, {Y, X}));
        } else if (l == 0) {
            if (S[r] == 'J') {
                res += getEndVal(r - l, {X, Y});
            } else {
                res += getEndVal(r - l, {Y, X});
            }
        } else if (r == S.size()) {
            if (S[l - 1] == 'C') {
                res += getEndVal(r - l, {X, Y});
            } else {
                res += getEndVal(r - l, {Y, X});
            }
        } else {
            res += getMidVal(r - l, S[l - 1], S[r], X, Y);
        }
        l = r;
    }
    for (int i = 1; i < S.size(); ++i) {
        if (S[i - 1] == 'C' && S[i] == 'J') {
            res += X;
        } else if (S[i - 1] == 'J' && S[i] == 'C') {
            res += Y;
        }
    }
    return res;
}

int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cout << "Case #" << t << ": " << solve() << endl;
    }

    return 0;
}
