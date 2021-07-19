#include "bits/stdc++.h"
using namespace std;

using area_t = int;
using height_t = int;
using phi = pair<height_t, size_t>;

area_t push(stack<phi>* s, const height_t cur_h, const size_t idx)
{
    assert(!s->empty());

    area_t res = 0;

    if (s->top().first < cur_h) {
        s->emplace(cur_h, idx);
    } else {
        auto last_idx = s->top().second;
        while (!s->empty() && s->top().first >= cur_h) {
            res = max(res, static_cast<area_t>(s->top().first * (idx - s->top().second)));
            last_idx = s->top().second;
            s->pop();
        }
        s->emplace(cur_h, last_idx);
    }

    return res;
}

int main()
{
    int N;
    cin >> N;

    stack<phi> s;
    s.emplace(0, 0);

    area_t max_area = 0;
    for (int i = 1; i <= N; ++i) {
        height_t h;
        cin >> h;
        max_area = max(max_area, push(&s, h, i));
    }
    max_area = max(max_area, push(&s, 0, N + 1));
    cout << max_area << endl;

    return 0;
}