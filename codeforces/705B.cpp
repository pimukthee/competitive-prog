#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, winner = 1, a;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &a);
        if (!(a & 1) && a != 1)
            winner ^= 1;
        printf("%d\n", winner + 1);
    }
    return 0;
}