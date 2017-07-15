#include <bits/stdc++.h>

using namespace std;

vector <int> c;
int n, k;

bool is_valid(int value, int mode) {
	long long sum = 0;
	for (auto money : c) {
		if (mode == 1) sum += max(0ll, 1ll * money - value);
		else sum += max(0ll, 1ll * value - money);
	}

	return sum <= 1ll * k;
}

int bsearch(int mode, long long sum) {
	int l, r, ans;
	if (mode) {
		l = (int)((sum + n - 1) / n);
		r = 1e9;
	} else {
		l = 1;
		r = (int) (sum / n;
	}
	while (l <= r) {
		int mid = (l + r) / 2;
		if (is_valid(mid, mode)) {
			if (mode) r = mid - 1;
			else l = mid + 1;
			ans = mid;
		} else {
			if (mode) l = mid + 1;
			else r = mid - 1;
		}
	}

	return ans;
}

int main() {
	scanf("%d %d", &n, &k);
	c.resize(n);
	for (int i = 0; i < n; ++i) scanf("%d", &c[i]);
	long long sum = accumulate(c.begin(), c.end(), 0ll);
	printf("%d\n", bsearch(1, sum) - bsearch(0, sum));

	return 0;
}