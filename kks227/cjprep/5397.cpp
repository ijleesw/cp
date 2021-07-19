#include "bits/stdc++.h"
using namespace std;

string dec(const string& s)
{
    list<char> li;
    auto it = begin(li);
    for (const auto c : s) {
        if (c == '-') {
            if (it != begin(li)) {
                it = li.erase(--it);
            }
        } else if (c == '<') {
            if (it != begin(li)) {
                --it;
            }
        } else if (c == '>') {
            if (it != end(li)) {
                ++it;
            }
        } else {
            it = ++li.insert(it, c);
        }
    }
    string res;
    res.reserve(li.size());
    for (const auto c : li) {
        res.push_back(c);
    }
    return res;
}

int main()
{
    int T;
    cin >> T;

    while (T--) {
        string s;
        cin >> s;
        cout << dec(s) << endl;
    }

    return EXIT_SUCCESS;
}