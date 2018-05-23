#include <bits/stdc++.h>

using namespace std;

int table[110][110], arr[110][110];

void increase_neighbor(int row, int col) {
    for (int i = -1; i <=1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            ++table[row+i][col+j];
        }
    }
}

int main() {
    bool ans = true;
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            scanf(" %c", &arr[i][j]);
            if (arr[i][j] == '*') increase_neighbor(i, j);
        }
    }


    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (arr[i][j] != '*') {
                ans = (ans && ((arr[i][j] == '.' && table[i][j] == 0) || (arr[i][j]-'0' == table[i][j])));
            }
        }
    }

    if (ans) {
        printf("YES");
    } else {
        printf("NO");
    }
    return 0;
}
