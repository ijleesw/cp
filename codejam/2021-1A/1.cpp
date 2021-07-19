#include "bits/stdc++.h"
using namespace std;

int solve() {
    int N;
    cin >> N;
    int cnt = 0;
    vector<int> last;
    
    while (N--) {
        int cur;
        cin >> cur;
        vector<int> digits;
        while (cur > 0) {
            digits.push_back(cur % 10);
            cur /= 10;
        }
        reverse(begin(digits), end(digits));
        const int orig_size = digits.size();

        if (digits.size() > last.size()) {
            ;
        } else if (digits.size() == last.size()) {
            bool gt = false;
            for (int i = 0; i < digits.size() && !gt; ++i) {
                gt = gt || (digits[i] > last[i]);
            }
            if (!gt) {
                digits.push_back(0);
            }
        } else {    // digits.size() < last.size()
            int cmp = 0;
            for (int i = 0; i < digits.size(); ++i) {
                if (last[i] < digits[i]) {
                    cmp = 1;
                    break;
                } else if (last[i] > digits[i]) {
                    cmp = -1;
                    break;
                }
            }
            if (cmp == 1) {
                for (int i = digits.size(); i < last.size(); ++i) {
                    digits.push_back(0);
                }
            } else if (cmp == -1) {
                for (int i = digits.size(); i < last.size() + 1; ++i) {
                    digits.push_back(0);
                }
            } else {    // cmp == 0 i.e. strictly smaller prefix
                long rem = 0;
                for (int i = digits.size(); i < last.size(); ++i) {
                    rem *= 10;
                    rem += last[i];
                }
                long added = rem + 1;
                long overflow = 1;
                for (int i = 0; i < last.size() - digits.size(); ++i) {
                    overflow *= 10;
                }
                if (added < overflow) {
                    vector<int> tmp;
                    for (int i = 0; i < last.size() - digits.size(); ++i) {
                        tmp.push_back(added % 10);
                        added /= 10;
                    }
                    reverse(begin(tmp), end(tmp));
                    move(begin(tmp), end(tmp), back_inserter(digits));

                } else {
                    for (int i = digits.size(); i < last.size() + 1; ++i) {
                        digits.push_back(0);
                    }
                }
            }
        }
        cout << "> ";
        for (auto d : digits) {
            cout << d;
        }
        cout << endl;

        cnt += digits.size() - orig_size;
        last = move(digits);
    }
    return cnt;
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
