#include "bits/stdc++.h"
using namespace std;

bool processAndCheck(vector<int>& arr) {
    int prev = arr[0];
    arr[0] = 0;
    for (int r = 0; r < arr.size(); ++r) {
        if (prev < arr[r]) {
            prev = arr[r];
            arr[r] = 0;
        }
    }
    arr.resize(remove(begin(arr), end(arr), 0) - begin(arr));
    return arr.empty();
}

int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> arr(N);
    for (auto& a : arr) {
        cin >> a;
    }

    while (K--) {
        if (processAndCheck(arr)) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}
