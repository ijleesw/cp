#include "bits/stdc++.h"
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    long n_friends = 0;

    queue<int> qs[21];

    string name;
    for (int i = 0; i < N; ++i) {
        cin >> name;
        auto& q = qs[name.size()];
        while (!q.empty() && q.front() < i - K) {
            q.pop();
        }
        n_friends += q.size();
        q.push(i);
    }
    cout << n_friends << endl;

    return 0;
}