#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while (T--) {
        list<char> li;
        string line; cin >> line;
        auto it = begin(li);

        for (auto c : line) {
            if (c == '<') {
                if (it != begin(li)) advance(it, -1);
            } else if (c == '>') {
                if (it != end(li)) advance(it, 1);
            } else if (c == '-') {
                if (it != begin(li)) {
                    advance(it, -1);
                    it = li.erase(it);
                }
            } else {
                li.insert(it, c);
            }
        }

        for (auto c : li) cout << c;
        cout << endl;
    }
    return 0;
}