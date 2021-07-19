#include "bits/stdc++.h"
using namespace std;

int main()
{
    int M;
    cin >> M;

    int s = 0;
    while (M--) {
        char cmd[10];
        int val;
        scanf("%s %d", cmd, &val);
        int bitval = 1 << val;
        switch (cmd[0]) {
            case 'a':
                if (cmd[1] == 'd') {
                    s |= bitval;
                } else {
                    s = ~0;
                }
                break;
            case 'r':
                s &= ~bitval;
                break;
            case 'c':
                printf("%d\n", (s & bitval ? 1 : 0));
                break;
            case 't':
                s ^= bitval;
                break;
            case 'e':
                s = 0;
                break;
            default:
                break;
        }
    }

    return EXIT_SUCCESS;
}
