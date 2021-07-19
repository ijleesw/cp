#include "bits/stdc++.h"
using namespace std;
using pii = pair<int, int>;

static constexpr int kPl = 100;
static constexpr int kQues = 10000;
static constexpr double kEps = 1e-7;

char buf[kQues + 1]{};
bool ans[kPl][kQues]{};
int playercnt[kPl];
int quescnt[kQues];

double sig(double x) {
    return 1. / (1 + exp(-x) + kEps);
}

double inv_s(double x) {
    double inv = log(x / (1 - x + kEps));
    return max(-3., min(inv, 3.));
}

int solve() {
    fill(begin(playercnt), end(playercnt), 0);
    fill(begin(quescnt), end(quescnt), 0);

    for (int i = 0; i < kPl; ++i) {
        scanf("%s", buf);
        for (int j = 0; j < kQues; ++j) {
            const bool correct = (buf[j] == '1');
            ans[i][j] = correct;
            playercnt[i] += static_cast<int>(correct);
            quescnt[j] += static_cast<int>(correct);
        }
    }

    vector<double> player_val(kPl);
    for (int i = 0; i < kPl; ++i) {
        player_val[i] = ((double)playercnt[i] / kQues);
    }
    vector<double> ques_val(kQues);
    for (int j = 0; j < kQues; ++j) {
        ques_val[j] = ((double)quescnt[j] / kPl);
    }

    vector<int> ugly(100, 0);
    for (int i = 0; i < kPl; ++i) {
        for (int j = 0; j < kQues; ++j) {
            const auto prob = sig(player_val[i] - ques_val[j]);
            const bool sample = ((double)rand() / RAND_MAX < prob);
            if (sample != ans[i][j]) {
                ++ugly[i];
            }
        }
    }
    for (int i = 0; i < kPl; ++i) {
        if (playercnt[i] < 0.49 * kQues) {
            ugly[i] = INT_MAX;
        }
    }
    for (int i = 0; i < kPl; ++i) {
        cout << i + 1 << " -> " << ugly[i] << endl;
    }
    return min_element(begin(ugly), end(ugly)) - begin(ugly) + 1;
}

int main()
{
    int T, P;
    cin >> T >> P;
    for (int t = 1; t <= T; ++t) {
        cout << "Case #" << t << ": " << solve() << endl;
    }

    return 0;
}
