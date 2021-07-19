#include "bits/stdc++.h"
using namespace std;

vector<char> ineq;

void print_max()
{
    int l = 0;
    int r = 0;
    vector<int> rem{0,1,2,3,4,5,6,7,8,9};
    while (l < ineq.size()) {
        // l == r, ineq[l] == '<'
        while (r < ineq.size() && ineq[r] == '<') {
            ++r;
        }
        vector<int> tmp;
        for (int i = 0; i < r - l + 1; ++i) {
            tmp.push_back(rem.back());
            rem.pop_back();
        }
        reverse(begin(tmp), end(tmp));
        for (const auto e : tmp) {
            cout << e;
        }
        while (r < ineq.size() && ineq[r] == '>') {
            ++r;
            if (r < ineq.size() && ineq[r] == '>') {
                cout << rem.back();
                rem.pop_back();
            }
        }
        l = r;
    }
    if (ineq.back() == '>') {
        cout << rem.back();
    }
    cout << endl;
}

void print_min()
{
    int l = ineq.size() - 1;
    int r = l;
    vector<int> rem{0,1,2,3,4,5,6,7,8,9};
    rem.resize(ineq.size() + 1);
    vector<int> res;
    while (l >= 0) {
        while (l >= 0 && ineq[l] == '>') {
            --l;
        }
        vector<int> tmp;
        for (int i = 0; i < r - l + 1; ++i) {
            tmp.push_back(rem.back());
            rem.pop_back();
        }
        reverse(begin(tmp), end(tmp));
        for (const auto e : tmp) {
            res.push_back(e);
        }
        while (l >= 0 && ineq[l] == '<') {
            --l;
            if (l >= 0 && ineq[l] == '<') {
                res.push_back(rem.back());
                rem.pop_back();
            }
        }
        r = l;
    }
    if (ineq.front() == '<') {
        res.push_back(rem.back());
    }
    reverse(begin(res), end(res));
    for (const auto e : res) {
        cout << e;
    }
    cout << endl;
}

int main()
{
    int K;
    cin >> K;
    ineq.resize(K);
    for (auto& i : ineq) {
        cin >> i;
    }
    print_max();
    print_min();

    return EXIT_SUCCESS;
}
