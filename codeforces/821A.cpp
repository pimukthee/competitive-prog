#include <bits/stdc++.h>

using namespace std;

int arr[55][55];


int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            scanf("%d", &arr[i][j]);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            bool found = false;
            if (arr[i][j] != 1) {
                for (int k = 1; k <= n; ++k) {
                    for (int l = 1; l <= n; ++l) {
                        if (k != j && l != i) {
                            if (arr[i][k] + arr[l][j] == arr[i][j])
                                found = true;
                        }
                    }
                }
                if (!found) {
                    printf("NO");
                    return 0;
                }
            }
        }
    }

    printf("YES");

    return 0;
}