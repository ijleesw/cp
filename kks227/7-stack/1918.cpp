#include "bits/stdc++.h"
using namespace std;

int level(char op) {
    if (op == '+' || op == '-') return 0;
    if (op == '*' || op == '/') return 1;
    return -1;
}

void handle(const string& eq, const int start, const int end, string& res) {
    stack<char> ops;
    int cur = start;

    while (cur <= end) {
        char e = eq[cur];
        if (e == '(') {
            int r = cur+1;
            int cnt = 1;
            while (cnt > 0 && r <= end) {
                if (eq[r] == '(') ++cnt;
                else if (eq[r] == ')') --cnt;
                ++r;
            }
            // cur='(', r=')'

            handle(eq, cur+1, r-2, res);
            cur = r;
            continue;
        }

        if (e < 'A' || e > 'Z') {   // op
            while (!ops.empty() && level(e) <= level(ops.top())) {
                res.push_back(ops.top());
                ops.pop();
            }
            ops.push(e);

        } else {    // symbol
            res.push_back(e);
        }

        ++cur;
    }

    while (!ops.empty()) {
        res.push_back(ops.top());
        ops.pop();
    }
}

int main() {
    string eq; cin >> eq;

    string res;
    handle(eq, 0, eq.size()-1, res);

    cout << res << endl;
    return 0;
}