#include <bits/stdc++.h>

using namespace std;

int arr[1005];

int main() {
    int n, k;
    cin >> n;
    while(n--) {
        cin >> k;
        arr[k] = 1;
    }

    for (int i = 1; i <= 1001; ++i) {
        if (arr[i] == 0) {
            cout << i << endl;
            break;
        }
    }
    
    return 0;
}