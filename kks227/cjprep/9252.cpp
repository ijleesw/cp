#include "bits/stdc++.h"
using namespace std;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    const int l1 = s1.size();
    const int l2 = s2.size();
    vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0));
    for (int i = 1; i <= l1; ++i) {
        for (int j = 1; j <= l2; ++j) {
            dp[i][j] = max(max(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1] + (s1[i - 1] == s2[j - 1]));
        }
    }
    cout << dp.back().back() << endl;

    string res;
    int i = l1;
    int j = l2;
    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1] && dp[i - 1][j - 1] + 1 == dp[i][j]) {
            res.push_back(s1[i - 1]);
            --i;
            --j;
        } else if (dp[i][j] == dp[i - 1][j]) {
            --i;
        } else {
            --j;
        }
    }
    reverse(begin(res), end(res));
    cout << res << endl;


    return EXIT_SUCCESS;
}