#include <bits/stdc++.h>

using namespace std;

int arr[105];

bool is_equal(int k, int n) {
    return all_of(arr ,arr + n, [](int i) {
        return (i % k == arr[0] % k);
    });
}

int main() {
    int n;

    cin >> n;
    for (int i = 0; i < n; ++i) cin >> arr[i];

    for (int i = 2; i <= 35000; ++i) {
        if (!p[i]) {
            for (int j = i +i; j <= 35000; j += i)
        }
        if (is_equal(i, n)) ans.push_back(i);

    }

    return 0;
}