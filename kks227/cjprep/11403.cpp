#include "bits/stdc++.h"
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<vector<int>> graph(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> graph[i][j];
        }
    }

    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                graph[i][j] |= (graph[i][k] && graph[k][j]);
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << graph[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}