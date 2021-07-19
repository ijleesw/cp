#include "bits/stdc++.h"
using namespace std;

string match[8]{"", "", "1", "7", "4", "2", "0", "8"};
string base[101]{"", "", "1", "7", "4", "2", "0", "8"};
string top[8]{"", "", "1", "7", "4", "2", "6", "8"};

bool numcmp(const string& lhs, const string& rhs)
{
    if (lhs.size() != rhs.size()) {
        return lhs.size() < rhs.size();
    }
    for (int i = 0; i < lhs.size(); ++i) {
        if (lhs[i] != rhs[i]) {
            return lhs[i] < rhs[i];
        }
    }
    return true;
}

const string& get_base(const int N)
{
    if (N <= 1) {
        return base[N];
    }
    auto& cur = base[N];
    if (!cur.empty()) {
        return cur;
    }
    vector<string> cands;
    for (int i = 2; i <= 7 && N - i >= 2; ++i) {
        cands.push_back(match[i] + get_base(N - i));
    }
    return cur = *min_element(begin(cands), end(cands), numcmp);
}

string get_minval(const int N)
{
    if (N <= 7) {
        return top[N];
    } else {
        vector<string> cands;
        for (int i = 2; i <= 7 && N - i >= 2; ++i) {
            cands.push_back(top[i] + get_base(N - i));
        }
        return *min_element(begin(cands), end(cands), numcmp);
    }
}

int main()
{
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;

        string maxval(N / 2, '1');
        if (N % 2 == 1) {
            maxval.front() = '7';
        }
        cout << get_minval(N) << ' ' << maxval << endl;
    }

    return EXIT_SUCCESS;
}
