#include "bits/stdc++.h"
using namespace std;

int main() {
    string line; cin >> line;
    int m; cin >> m;

    list<char> li;
    for (auto c : line) li.push_back(c);
    auto cur = end(li);

    while (m--) {
        char op; cin >> op;
        if (op == 'L') {
            if (cur != begin(li)) advance(cur, -1);
        } else if (op == 'D') {
            if (cur != end(li)) advance(cur, 1);
        } else if (op == 'B') {
            if (cur != begin(li)) {
                advance(cur, -1);
                cur = li.erase(cur);
            }
        }
        if (op == 'P') {
            char c; cin >> c;
            li.insert(cur, c);
        }
    }

    for (auto c : li) cout << c;
    cout << endl;
    return 0;
}