#include "bits/stdc++.h"
using namespace std;

int main() {
    int N; cin >> N;
    string eq; cin >> eq;
    unordered_map<char, double> val;
    for (int i = 0; i < N; ++i) {
        double v; cin >> v;
        val['A'+i] = v;
    }
    // end of input

    stack<double> res;
    for (const auto e : eq) {
        if ('A' <= e && e <= 'Z') {
            res.push(val[e]);

        } else {
            double r = res.top(); res.pop();
            double l = res.top(); res.pop();
            switch (e) {
                case '+':
                    res.push(l+r);
                    break;
                case '-':
                    res.push(l-r);
                    break;
                case '*':
                    res.push(l*r);
                    break;
                case '/':
                    res.push(l/r);
                    break;
                default:
                    assert(0);
                    break;
            }
        }
    }

    assert(res.size() == 1);
    printf("%.2f\n", res.top());
    return 0;
}