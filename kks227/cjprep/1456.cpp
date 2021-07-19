#include "bits/stdc++.h"
using namespace std;

int main()
{
    size_t A, B;
    cin >> A >> B;

    size_t upper = sqrt(B);

    const auto almost = [A, B](size_t n) {
        int cnt = 0;
        size_t a = (A + n - 1) / n, b = B / n;
        size_t _n = n;
        for (int i = 1; n <= b; ++i) {
            if (a <= n) {
                ++cnt;
            }
            n *= _n;
        }
        return cnt;
    };

    vector<bool> visited(upper + 1, false);
    size_t cnt = 0;
    for (size_t i = 2; i <= upper; ++i) {
        if (!visited[i]) {
            cnt += almost(i);
            for (int j = i; j <= upper; j += i) {
                visited[j] = true;
            }
        }
    }
    cout << cnt << endl;

    return 0;
}
