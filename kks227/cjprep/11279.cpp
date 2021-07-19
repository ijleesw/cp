#include "bits/stdc++.h"
using namespace std;

void solve1(const int N)
{
    priority_queue<int, vector<int>, less<int>> pq;
    for (int i = 0; i < N; ++i) {
        int a;
        scanf("%d", &a);
        if (a == 0) {
            if (pq.empty()) {
                printf("0\n");
            } else {
                printf("%d\n", pq.top());
                pq.pop();
            }
        } else {
            pq.push(a);
        }
    }
}

int main()
{
    int N;
    cin >> N;
    solve1(N);

    return EXIT_SUCCESS;
}