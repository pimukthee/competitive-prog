#include <bits/stdc++.h>

using namespace std;

int cnt[50];
char str[2005];

int main() {
    int n;
    long long ans = 0;
    scanf("%d %s", &n, str + 1);

    for (int i = 1; i <= n; ++i) {
        int found = 0;
        for (int j = i + 1; j <= n; ++j) {
            if (str[i] == str[j]) ans += found;
            found += cnt[str[j] - 'a'];
        }
        cnt[str[i] - 'a']++;
    }

    printf("%lld", ans);

    return 0;
}