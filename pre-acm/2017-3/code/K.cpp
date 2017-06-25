#include <bits/stdc++.h>

using namespace std;

pair <int[10005], int> mat[105];
long long mul[105];
int row[105];

int main() {
    int r, c, n, x, y, z;
    scanf("%d %d", &r, &c);
    for (int i = 1; i <= r; ++i) {
        mat[i].second = 1;
        row[i] = i;
        for (int j = 1; j <= c; ++j) scanf("%d", &mat[i].first[j]);
    }
    scanf("%d", &n);
    while (n--) {
        scanf("%d %d %d", &x, &y, &z);
        if (x == 1) swap(row[y], row[z]);
        else if (x == 2) mat[row[y]].second *= z;
        else printf("%d\n", mat[row[y]].first[z] * mat[row[y]].second);
    }

    return 0;
}
