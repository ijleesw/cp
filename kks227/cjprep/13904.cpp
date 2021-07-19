#include "bits/stdc++.h"
using namespace std;
using pii = pair<int, int>;

int main()
{
    int N; cin >> N;
    vector<pii> ps; // (day, value)
    int max_day = 1;
    for (int i = 0; i < N; ++i) {
        int a, b; cin >> a >> b;
        max_day = max(max_day, a);
        ps.emplace_back(a, b);
    }
    sort(begin(ps), end(ps), [](const auto& l, const auto& r) { return l.second > r.second; });

    set<int, greater<int>> s;
    for (int i = 1; i <= max_day; ++i) {
        s.insert(i);
    }

    int total = 0;
    for (const auto& p : ps) {
        auto day = p.first;
        auto val = p.second;

        auto it = s.lower_bound(day);
        if (it != end(s)) {
            total += val;
            s.erase(it);
        }
    }

    cout << total << endl;
    return 0;
}

//int main()
//{
//    int N;
//    cin >> N;
//    multiset<pii> ps;  // (value, day)
//    int max_day = -1;
//    for (int i = 0; i < N; ++i) {
//        int a, b;
//        cin >> a >> b;
//        max_day = max(max_day, a);
//        ps.emplace(b, a);
//    }
//
//    int total = 0;
//    for (int day = max_day; day >= 1; --day) {
//        for (auto it = ps.rbegin(); it != ps.rend(); ++it) {
//            if (it->second >= day) {
//                total += it->first;
//                ps.erase(--it.base());
//                break;
//            }
//        }
//    }
//
//    cout << total << endl;
//
//    return 0;
//}