#include <bits/stdc++.h>

using namespace std;

int sumDivisorsOfDivisors(int n)
{

    map<int, int> mp;
    for (int j = 2; j <= sqrt(n); j++) {
        int count = 0;
        while (n % j == 0) {
            n /= j;
            count++;
        }

        if (count)
            mp[j] = count;
    }

    if (n != 1)
        mp[n] = 1;

    int ans = 1;
    for (auto it : mp) {
        int pw = 1, k = 1;
        int sum = 0;
        cout << it.first << "====" << endl;
        for (int i = it.second + 1; i >= 1; i--) {
            cout << k << endl;
            sum += k;
            k = (k * it.first) + 1;
            pw *= it.first;
        }
        ans *= sum;
    }

    return ans;
}

int main() {
    int n = 25;
    cout << sumDivisorsOfDivisors(n) << endl;

    return 0;
}