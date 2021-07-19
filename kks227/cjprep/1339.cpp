#include "bits/stdc++.h"
using namespace std;

int eval(vector<int>& vals, const vector<char>& chars, const vector<string>& words)
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

int DFS(vector<int>& vals, set<int>& rems, const vector<char>& chars, const vector<string>& words)
{
    if (vals.size() == chars.size()) {
        return eval(vals, chars, words);

    } else {
        int max_res = -1;
        int remsArr[10];
        int rems_cnt = 0;
        for (const auto r : rems) {
            remsArr[rems_cnt++] = r;
        }
        for (int i = 0; i < rems_cnt; ++i) {
            const int r = remsArr[i];
            vals.push_back(r);
            rems.erase(r);
            max_res = max(max_res, DFS(vals, rems, chars, words));
            rems.insert(r);
            vals.pop_back();
        }
        return max_res;
    }
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

    vector<int> vals;
    set<int> rems;
    for (int i = 0; i <= 9; ++i) {
        rems.insert(i);
    }
    cout << DFS(vals, rems, chars, words) << endl;

    return EXIT_SUCCESS;
}
