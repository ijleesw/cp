#include "bits/stdc++.h"
using namespace std;
using pii = pair<int, int>;

int main()
{
    int L, N, rf, rb;
    cin >> L >> N >> rf >> rb;

    vector<pii> stops;  // (pos, profit)
    stops.reserve(N);
    for (int i = 0; i < N; ++i) {
        int a, b; cin >> a >> b;
        stops.emplace_back(a, b);
    }
    sort(begin(stops), end(stops), [](const auto& l, const auto& r) { return l.second > r.second; });

    long total_profit = 0;
    int meeting_idx = 0;

    for (const auto& stop : stops) {
        const auto pos = stop.first;
        const auto profit = stop.second;

        if (pos > meeting_idx) {
            total_profit += static_cast<long>(rf - rb) * (pos - meeting_idx) * profit;
            meeting_idx = pos;
        }
    }

    cout << total_profit << endl;
    return 0;
}