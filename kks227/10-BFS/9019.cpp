#include "bits/stdc++.h"
using namespace std;

struct Candidate
{
    int value;
    string cmds;
};

static const int kMod = 10000;

void solve(const int from, const int to)
{
    vector<bool> seen(10000, false);

    queue<Candidate> q;
    Candidate start; start.value = from; seen[start.value] = true;
    q.push(start);

    while (true) {
        const auto front = q.front(); q.pop();
        if (front.value == to) {
            cout << front.cmds << "\n";
            return;
        }
        auto d = front; d.value = (front.value * 2) % kMod; d.cmds.push_back('D');
        if (!seen[d.value]) {
            seen[d.value] = true;
            q.push(d);
        }
        auto s = front; s.value = (front.value + kMod - 1) % kMod; s.cmds.push_back('S');
        if (!seen[s.value]) {
            seen[s.value] = true;
            q.push(s);
        }
        auto l = front; l.value = (front.value * 10) % kMod + (front.value / (kMod / 10)); l.cmds.push_back('L');
        if (!seen[l.value]) {
            seen[l.value] = true;
            q.push(l);
        }
        auto r = front; r.value = (front.value / 10) + (front.value % 10 * (kMod / 10)); r.cmds.push_back('R');
        if (!seen[r.value]) {
            seen[r.value] = true;
            q.push(r);
        }
    }
}

int main()
{
    int T; cin >> T;
    while (T--) {
        int from, to;
        cin >> from >> to;
        solve(from, to);
    }
    return 0;
}