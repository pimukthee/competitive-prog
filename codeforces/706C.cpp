#include <bits/stdc++.h>

using namespace std;

long long n, c[110000], dp[2][110000], s;
string a[2][110000];

int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> c[i];
	for (int i = 1; i <= n; ++i) {
		cin >> a[0][i];
		a[1][i] = a[0][i];
		reverse(a[1][i].begin(), a[1][i].end());
	}
	dp[1][1] = c[1];
	for (int i = 2; i <= n; ++i)
		for (int k = 0; k < 2; ++k) {
			dp[k][i] = 1e15;
			for (int j = 0; j < 2; ++j)
				if (a[j][i - 1] <= a[k][i]) dp[k][i] = min(dp[k][i], dp[j][i - 1] + k * c[i]);
		}
	s = min(dp[0][n], dp[1][n]);
	cout << ((s == (1e15)) ? -1 : s);

    return 0;
}