#include <bits/stdc++.h>

using namespace std;

int main () {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n ; ++i) {
        printf("I %s %s", (i & 1) ? "hate" : "love", i == n ? "it\n":"that ");
    }
    return 0;
}