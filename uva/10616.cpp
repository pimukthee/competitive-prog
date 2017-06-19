#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <utility>
#include <algorithm>
#include <cstring>
#define pb push_back
#define mp make_pair
#define sqr(x) x*x
#define LL long long
#define F first
#define S second
#define vi vector<int>
#define pi pair<int,int>
#define N 201
#define M 21
using namespace std;
int n, q, d, m, t=1;
int p[N];
unsigned long long D[N][M][M];
int main() {
    while (scanf("%d %d\n", &n, &q)>0&&n&&q) {
        for (int i=1; i<=n; i++)
            scanf("%d", &p[i]);
        printf("SET %d:\n", t++);
        for (int i=1; i<=q; i++) {
            scanf("%d %d", &d, &m);
            printf("QUERY %d: ", i);
            memset(D, 0, sizeof(D));
            for (int i=0; i<=n; i++)
                D[i][0][0]=1;
            for (int i=1; i<=n; i++)
                for (int j=1; j<=m; j++)
                    for (int k=0; k<d; k++) {
                        int r=(k-p[i]%d)%d;
                        D[i][j][k]=D[i-1][j][k]+D[i-1][j-1][r>=0?r:r+d];
                    }
            printf("%lld\n", D[n][m][0]);
        }
    }
    return 0;
}
