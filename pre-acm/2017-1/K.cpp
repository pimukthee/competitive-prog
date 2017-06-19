#include <iostream>
#include <algorithm>
using namespace std;

int dp[1000000+10];
int p[1000000+10];
int main(){
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> p[i];
	}
	for(int i=0;i<=1000000;i++)
		dp[i] = 20000000;

	dp[1] = 0;
	for(int i=1;i<n;i++){
		dp[i+1] = min(dp[i]+1,dp[i+1]); 	
		if(i+p[i] <= n)
			dp[i+p[i]] = min(dp[i]+1,dp[i+p[i]]);
	}
	cout << dp[n] << endl;
	return 0;
}
