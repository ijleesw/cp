#include "bits/stdc++.h"
using namespace std;

int main()
{
    string Y;
    cin >> Y;
    string_view y(Y);

    int n;
    cin >> n;
    vector<string> xs(n);
    for (int i = 0; i < n; ++i) {
        cin >> xs[i];
    }

    vector<bool> fits(y.size() + 1, false);
    fits.back() = true;

    for (int i = y.size() - 1; i >= 0; --i) {
        for (int j = 0; j < n && !fits[i]; ++j) {
            const auto& x = xs[j];
            const auto is_prefix = y.substr(i).rfind(x, 0) == 0;
            const auto len_after_concat = i + x.size();
            fits[i] = is_prefix && fits[len_after_concat];
        }
    }

    cout << static_cast<int>(fits[0]) << endl;
    return 0;
}