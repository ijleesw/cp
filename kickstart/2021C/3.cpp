#include "bits/stdc++.h"
using namespace std;

struct State {
    int r, s, p, from;
    double exp;
};

string solve() {
    double W, E;
    cin >> W >> E;

    double exp = 0;

    double r = 1;
    double s = 0;
    double p = 0;
    string res = "R";

    vector<vector<State>> dp(61, vector<State>(3));
    dp[1][0] = {1, 0, 0, W / 3};
    dp[1][1] = {0, 1, 0, W / 3};
    dp[1][2] = {0, 0, 1, W / 3};

    for (int i = 2; i <= 60; ++i) {
        double r_max = 0;
        int r_idx = 0;
        double s_max = 0;
        int s_idx = 0;
        double p_max = 0;
        int p_idx = 0;

        for (int j = 0; j < 3; ++j) {
            const auto [r, s, p, exp] = dp[i - 1][j];

            double r_prob = s / (i - 1);
            double s_prob = p / (i - 1);
            double p_prob = r / (i - 1);

            double r_win = s_prob;
            double s_win = p_prob;
            double p_win = r_prob;

            double r_draw = r_prob;
            double s_draw = s_prob;
            double p_draw = p_prob;

            double r_exp = r_win * W + r_draw + E;
            double s_exp = s_win * W + s_draw + E;
            double p_exp = p_win * W + p_draw + E;

            if (r_exp > r_max) {
                r_exp = r_max;
                r_idx = j;
            }
            if (s_exp > s_max) {
                s_exp = s_max;
                s_idx = j;
            }
            if (p_exp > p_max) {
                p_exp = p_max;
                p_idx = j;
            }
        }

        if (r_exp >= s_exp && r_exp >= p_exp) {
            res.append("R");
            exp += r_exp;
            ++r;
        } else if (s_exp >= r_exp && s_exp >= p_exp) {
            res.append("S");
            exp += s_exp;
            ++s;
        } else {
            res.append("P");
            exp += p_exp;
            ++p;
        }
    }
    //cout << "exp: " << exp << endl;
    return res;
}

int main()
{
    int T, X;
    cin >> T >> X;
    for (int t = 1; t <= T; ++t) {
        cout << "Case #" << t << ": " << solve() << endl;
    }

    return 0;
}
