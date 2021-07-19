#include "bits/stdc++.h"
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<string> names(N + 1);
    unordered_map<string, int> nameMap;
    for (int i = 1; i <= N; ++i) {
        char c[21]{};
        scanf("%s", c);
        names[i] = c;
        nameMap[names[i]] = i;
    }
    for (int i = 0; i < M; ++i) {
        char c[21]{};
        scanf("%s", c);
        if (isdigit(c[0])) {
            printf("%s\n", names[atoi(c)].c_str());
        } else {
            printf("%d\n", nameMap[c]);
        }
    }

    return EXIT_SUCCESS;
}