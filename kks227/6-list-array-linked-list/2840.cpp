#include "bits/stdc++.h"
using namespace std;

int main() {
    int n, k; cin >> n >> k;

    auto getNext = [&](int& cur, int step) { cur = (cur - step + n * 10000) % n; };

    string res(n, '?');
    int cur = 0;
    bool isValid = true;

    for (int i = 0; i < k; ++i) {
        int s; char c; cin >> s >> c;
        getNext(cur, s);

        if (res[cur] == '?') {
            res[cur] = c;
        } else {
            isValid &= (res[cur] == c);
        }
    }

    vector<bool> appeared(26, false);
    for (auto c : res) {
        if (c == '?') continue;

        if (appeared[c-'A']) {
            isValid = false;
            break;
        } else {
            appeared[c-'A'] = true;
        }
    }

    if (!isValid) {
        cout << '!' << endl;
    } else {
        rotate(begin(res), begin(res) + cur, end(res));
        cout << res << endl;
    }
    return 0;
}