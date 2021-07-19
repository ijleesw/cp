#include "bits/stdc++.h"
using namespace std;

int eval(const vector<int>& vals, const vector<char>& chars, const vector<string>& words)
{
    int valmap[26];
    for (int i = 0; i < chars.size(); ++i) {
        valmap[chars[i] - 'A'] = vals[i];
    }

    int sum = 0;
    for (const auto& word : words) {
        int cur_val = 0;
        for (const auto c : word) {
            cur_val *= 10;
            cur_val += valmap[c - 'A'];
        }
        sum += cur_val;
    }
    return sum;
}

template <typename ITER>
bool next_permutation(ITER b, ITER e, int skip_cnt)
{
    for (int i = 0; i < skip_cnt; ++i) {
        if (!next_permutation(b, e)) {
            return false;
        }
    }
    return true;
}

int main()
{
    int N;
    cin >> N;
    vector<string> words(N);
    for (auto& w : words) {
        cin >> w;
    }

    vector<char> chars;
    for (const auto& w : words) {
        std::copy(begin(w), end(w), back_inserter(chars));
    }
    sort(begin(chars), end(chars));
    chars.resize(unique(begin(chars), end(chars)) - begin(chars));

    vector<int> vals(10);
    for (int i = 0; i <= 9; ++i) {
        vals[i] = i;
    }

    int skip_cnt = 1;
    for (int i = 1; i <= 10 - chars.size(); ++i) {
        skip_cnt *= i;
    }

    int max_res = -1;
    do {
        max_res = max(max_res, eval(vals, chars, words));
    } while (next_permutation(begin(vals), end(vals), skip_cnt));
    cout << max_res << endl;

    return EXIT_SUCCESS;
}
