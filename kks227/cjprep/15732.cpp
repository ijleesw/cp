#include "bits/stdc++.h"
using namespace std;

struct Rule
{
    int from;
    int to;
    int dist;
};

long n_le_dotori(const vector<Rule>& rules, const int box_guess)
{
    long guess_le = 0;
    for (const auto& rule : rules) {
        guess_le += (box_guess < rule.from ? 0 : 1 + (min(rule.to, box_guess) - rule.from) / rule.dist);
    }
    return guess_le;
}

int main()
{
    int n_box, n_rule, n_dotori;
    cin >> n_box >> n_rule >> n_dotori;

    vector<Rule> rules(n_rule);
    for (int i = 0; i < n_rule; ++i) {
        auto& rule = rules[i];
        cin >> rule.from >> rule.to >> rule.dist;
    }
    // end of input

    int l = 1;
    int r = n_box;
    int res = -1;

    while (l <= r) {
        int m = (l + r) / 2;

        if (n_le_dotori(rules, m) >= n_dotori) {
            res = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    assert(res != -1);

    cout << res << endl;

    return 0;
}