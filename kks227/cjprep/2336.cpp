#include "bits/stdc++.h"
using namespace std;

struct Stu
{
    int _1, _2, _3;
    bool operator<(const Stu& rhs) const {
        return std::tie(_1, _2, _3) < std::tie(rhs._1, rhs._2, rhs._3);
    }
};

int upper_pow2(int n)
{
    return 1 << (32 - __builtin_clz(n - 1));
}

void build(vector<int>& seg)
{
    const int N2 = seg.size() / 2;
    for (int i = N2 - 1; i >= 1; --i) {
        seg[i] = min(seg[i * 2], seg[i * 2 + 1]);
    }
}


int main()
{
    int N;
    cin >> N;
    vector<Stu> stu(N);
    for (auto& s : stu) {
        scanf("%d", &s._1);
        --s._1;
    }
    for (auto& s : stu) {
        scanf("%d", &s._2);
        --s._2;
    }
    for (auto& s : stu) {
        scanf("%d", &s._3);
        --s._3;
    }
    sort(begin(stu), end(stu));

    const int N2 = upper_pow2(N);
    vector<int> seg(N2 * 2, INT_MAX);
    for (int i = 0; i < N; ++i) {
        seg[N2 + stu[i]._2] = stu[i]._3;
    }
    build(seg);

    return EXIT_SUCCESS;
}