#include <bits/stdc++.h>

using namespace std;
int a[100005];

int main() {
    int n, k;

    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);

    int i = k;
    while(a[i] == a[k]) i++;
    while(k >= 1 && a[k] == a[i - 1]) k--;

    printf("%d", (i == n + 1) ? k : -1);

    return 0;
}
