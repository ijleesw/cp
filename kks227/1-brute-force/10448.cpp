#include "bits/stdc++.h"
using namespace std;


int main() {
    vector<int> tri;
    bool arr[1001];
    for (int i = 1, sum = 1; sum <= 1500; ++i, sum += i) tri.push_back(sum);
    for (int i = 0; i < tri.size(); ++i) {
        for (int j = i; j < tri.size(); ++j) {
            for (int k = j; k < tri.size(); ++k) {
                int sum = tri[i] + tri[j] + tri[k];
                if (sum <= 1000) arr[sum] = 1;
            }
        }
    }

    int T; cin >> T;

    while (T--) {
        bool b = false;
        int n; cin >> n;
        cout << (int)arr[n] << endl;
    }

    return 0;
}