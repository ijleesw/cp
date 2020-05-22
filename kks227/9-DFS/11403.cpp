#include "bits/stdc++.h"
using namespace std;

int main()
{
    int N; cin >> N;
    vector<vector<int>> v(N, vector<int>(N, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> v[i][j];
        }
    }

    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                v[i][j] |= (v[i][k] && v[k][j]);
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << v[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}