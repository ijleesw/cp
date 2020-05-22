#include "bits/stdc++.h"
using namespace std;

int isGood(const string& word) {
    stack<char> s;
    for (const auto c : word) {
        if (!s.empty() && s.top() == c) s.pop();
        else s.push(c);
    }
    return (int)s.empty();
}

int main() {
    int n; cin >> n;
    int cnt = 0;
    while (n--) {
        string word; cin >> word;
        cnt += isGood(word);
    }
    cout << cnt << endl;
    return 0;
}