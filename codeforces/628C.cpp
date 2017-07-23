#include <bits/stdc++.h>

using namespace std;

char s[100005];
vector <char> ans;

int main() {
    int n, k;

    scanf("%d %d %s", &n, &k, s);

    for (int i = 0; i < n; ++i) {
        int left = min(abs(s[i] - 'a'), k);
        int right = min(abs(s[i] - 'z'), k);
        if (left > right) {
            ans.push_back(s[i] - left);
        } else {
            ans.push_back(s[i] + right);
        }
        k -= max(left, right);
    }

    if (k > 0) {
        printf("-1");
    }else {
        for (auto c : ans) {
            printf("%c", c);
        }
    }

    return 0;
}