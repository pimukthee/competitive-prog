#include <bits/stdc++.h>

using namespace std;

int a1[5][5];

int main() {
    int aa, bb, a, b;
    scanf("%d %d", &a, &b);
    for(int i = 0; i < 2; ++i) scanf("%d %d", &a1[i][0], &a1[i][1]);
    for(int i = 0; i < 2; ++i) {
        for(int j = 0; j < 2; ++j) {
            aa = a1[0][i] + a1[1][j];
            bb = max(a1[0][i ^ 1], a1[1][j ^ 1]);
            if((aa<=a && bb<=b) || (aa<=b && bb<=a)) {
                printf("YES\n");
                return 0;
            }
        }
    }

    printf("NO\n");
    
    return 0;
}
