#include "bits/stdc++.h"
using namespace std;

int N;

vector<int> get_primes()
{
    vector<int> res;
    vector<bool> visited(N + 1, false);

    for (int i = 2; i < visited.size(); ++i) {
        if (!visited[i]) {
            res.push_back(i);
            for (int j = i; j < visited.size(); j += i) {
                visited[j] = true;
            }
        }
    }
    return res;
}

int main()
{
    cin >> N;
    const auto primes = get_primes();

    int l = 0;
    int r = 0;
    int sum = 0;
    int cnt = 0;

    while (true) {
        if (sum >= N) {
            sum -= primes[l++];
        } else {    // sum < N
            if (r == primes.size()) {
                break;
            } else {
                sum += primes[r++];
            }
        }
        if (sum == N) {
            ++cnt;
        }
    }
    cout << cnt << endl;

    return EXIT_SUCCESS;
}
