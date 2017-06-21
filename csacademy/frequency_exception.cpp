#include <bits/stdc++.h>

using namespace std;

int arr[1005];
pair <int, int> freq[1005];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
    sort(arr, arr + n);
    for (int i = 0; i < n;) {
        int cnt = count(arr, arr + n, arr[i]);
        freq[cnt].second++;
        freq[cnt].first = arr[i];
        i += cnt;
    }
    for (int i = 1; i <= 1000; ++i) {
        if (freq[i].second == 1) {
            printf("%d\n", freq[i].first);
        }
    }

    return 0;
}