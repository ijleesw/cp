#include "bits/stdc++.h"
using namespace std;

int main()
{
    int N;
    cin >> N;
    priority_queue<long, vector<long>, greater<long>> pq;
    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;
        pq.push(x);
    }
    long sum = 0;
    while (pq.size() >= 2) {
        long a = pq.top();
        pq.pop();
        long b = pq.top();
        pq.pop();
        sum += (a + b);
        pq.push(a + b);
    }
    cout << sum << endl;

    return EXIT_SUCCESS;
}