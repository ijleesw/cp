#include "bits/stdc++.h"
using namespace std;

using psi = pair<string, int>;
using pli = pair<long, int>;

long toLong(const string& s) {
    long res = 0;
    for (const auto c : s) {
        res *= 2;
        res += static_cast<int>(c == '1');
    }
    return res;
}

string toString(long l) {
    string res;
    if (l == 0) {
        res = "0";
    } else {
        while (l > 0) {
            res.append(to_string(l % 2));
            l /= 2;
        }
    }
    reverse(begin(res), end(res));
    return res;
}

string solve() {
    string from, to;
    cin >> from >> to;

    unordered_set<long> visited;
    
    queue<pli> q;
    q.emplace(toLong(from), 0);
    visited.insert(toLong(from));

    const int max_step = 15;
    int prev_step = 0;

    while (!q.empty()) {
        auto&& [v, step] = q.front();
        // if (prev_step != step) {
        //     cout << "\n";
        // }
        // prev_step = step;
        // cout << "cur: " << cur << ", step: " << step << endl;
        q.pop();

        auto cur = toString(v);

        if (cur == to) {
            return to_string(step);
        }

        if (step > max_step) {
            break;
        }

        auto notStr = cur;
        int start = 0;
        while (start < notStr.size() && notStr[start] == '1') {
            ++start;
        }
        if (start == notStr.size()) {
            notStr = "0";
        } else {
            notStr = notStr.substr(start);
            for (auto& c : notStr) {
                c = (c == '0' ? '1' : '0');
            }
        }
        if (visited.count(toLong(notStr)) == 0) {
            visited.insert(toLong(notStr));
            q.emplace(toLong(notStr), step + 1);
        }
        
        cur.append("0");
        if (visited.count(toLong(cur)) == 0) {
            visited.insert(toLong(cur));
            q.emplace(toLong(cur), step + 1);
        }
    }

    return "IMPOSSIBLE";
}

int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cout << "Case #" << t << ": " << solve() << endl;
    }

    return 0;
}

