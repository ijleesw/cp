#include "bits/stdc++.h"
using namespace std;
using pii = pair<int, int>;

vector<pii> last(3, {0, 0});
vector<pii> cur(3, {0, 0});

int main()
{
    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        int input[3];
        scanf("%d %d %d", &input[0], &input[1], &input[2]);

        cur[0].first = min(last[0].first, last[1].first) + input[0];
        cur[0].second = max(last[0].second, last[1].second) + input[0];

        cur[1].first = min(min(last[0].first, last[1].first), last[2].first) + input[1];
        cur[1].second = max(max(last[0].second, last[1].second), last[2].second) + input[1];

        cur[2].first = min(last[1].first, last[2].first) + input[2];
        cur[2].second = max(last[1].second, last[2].second) + input[2];

        swap(cur, last);
    }

    cout << max(max(last[0].second, last[1].second), last[2].second) << ' '
         << min(min(last[0].first, last[1].first), last[2].first) << endl;

    return EXIT_SUCCESS;
}
