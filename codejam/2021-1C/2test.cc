#include "bits/stdc++.h"
using namespace std;

long get(long pfval, const int len) {
    string res;
    while (res.size() < len) {
        res.append(to_string(pfval));
        ++pfval;
    }
    if (res.size() == len) {
        return atol(res.c_str());
    } else {
        return LONG_MAX;
    }
}

long solve(string s) {
    // string s;
    // cin >> s;

    const auto orig = atol(s.c_str());
    long res = LONG_MAX / 2;

    for (int l = 1; l <= s.length() / 2; ++l) {
        const auto prefix = s.substr(0, l);
        const auto pfval = atol(prefix.c_str());

        for (long pf = pfval; ; ++pf) {
            const auto newval = get(pf, s.length());
            if (newval > orig) {
                res = min(res, newval);
            }

            const auto cur_s = to_string(pf);
            if (cur_s.size() != prefix.size() || (cur_s.size() >= 2 && cur_s[cur_s.size() - 2] != prefix[prefix.size() - 2])) {
                break;
            }
        }
    }

    string onePre = "1";
    for (int l = 1; l <= (s.length() + 1) / 2; ++l) {
        const auto pfval = atol(onePre.c_str());
        const auto newval = get(pfval, s.length() + 1);
        if (newval > orig) {
            res = min(res, newval);
        }
        onePre.append("0");
    }

    return res;
}

bool isCand(const long n) {
    const auto s = to_string(n);

    for (int l = 1; l <= s.length() / 2; ++l) {
        const auto prefix = s.substr(0, l);
        const auto pfval = atol(prefix.c_str());

        if (get(pfval, s.length()) == n) {
            return true;
        }
    }
    return false;
}

int main()
{
    vector<long> cands;
    for (long i = 1; i <= 1234567; ++i) {
        if (isCand(i)) {
            cands.push_back(i);
        }
    }

    for (long i = 1; i <= 100000; ++i) {
        const auto ans = *upper_bound(begin(cands), end(cands), i);
        const auto my = solve(to_string(i));
        if (ans != my) {
            cout << i << ' ' << ans << ' ' << my << endl;
        }
    }

    return 0;
}
