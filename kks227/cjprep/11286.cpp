#include "bits/stdc++.h"
using namespace std;

void solve1(const long N)
{
    priority_queue<long, vector<long>, greater<long>> pq;
    for (long i = 0; i < N; ++i) {
        long a;
        scanf("%ld", &a);
        if (a == 0) {
            if (pq.empty()) {
                printf("0\n");
            } else {
                long top = pq.top();
                if (top % 2 == 0) {
                    top = -(top / 2);
                } else {
                    top = top / 2;
                }
                printf("%ld\n", top);
                pq.pop();
            }
        } else {
            if (a < 0) {
                a *= -1;
                a *= 2;
            } else {
                a *= 2;
                a += 1;
            }
            pq.push(a);
        }
    }
}

int main()
{
    long N;
    cin >> N;
    solve1(N);

    return EXIT_SUCCESS;
}