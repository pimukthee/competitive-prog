#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, ans = 0, last = 0, a;
    vector <int> odd;
    
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) { 
        scanf("%d", &a);
        if (abs(a) % 2 == 1) {
            odd.push_back(a);
        } else if (a > 0) {
            ans += a;
        }
    }

    sort(odd.begin(), odd.end());
    reverse(odd.begin(), odd.end());
    ans += odd[0];
    for (int i = 1; i < odd.size(); ++i) {
        if (odd[i] > 0) {
            ans += odd[i];
            last = odd[i];
        } else if (abs(ans + odd[i]) % 2 == 1){
            ans = max(ans + odd[i], ans - last);
            break;
        }
    }
    if (ans % 2 == 0) ans -= last;

    printf("%d\n", ans);

    return 0;
}

