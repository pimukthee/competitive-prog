#include <bits/stdc++.h>

using namespace std;

int mem[200010];
int dp[200010];

int main() {
	int n, k, q, l, r;
	scanf("%d %d %d", &n, &k, &q);
	for(int i = 0;i < n; ++i) {
		scanf("%d %d", &l, &r);
		mem[l]++;
		mem[r + 1]--;	
	}
	for (int i = 1; i <= 200000; ++i) {
		mem[i] = mem[i - 1] + mem[i];
		dp[i] = dp[ i - 1] + (mem[i - 1] >= k ? 1 : 0);
	}
	for(int i = 0; i < q; ++i) {
		scanf("%d %d", &l, &r);
		printf("%d\n", dp[r] - dp[l - 1]);
	}

	return 0;
}
