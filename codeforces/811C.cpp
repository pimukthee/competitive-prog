#include <iostream>
#include <cstdio>
#include <map>
#include <cstring>
using namespace std;
typedef pair<int,int> ii;
int v[5000+10],w[5010][5010];

int main(){
	int n,a[5000+10],dp[5010];

	bool used[5010];
	memset(v,0,sizeof(v));
	memset(w,0,sizeof(w));

	cin >> n;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	
	map<int,ii> range; 
		
	for(int i=1;i<=n;i++){
		if(range.find(a[i]) == range.end()){
			range[a[i]] = ii(i,i);
		}	
		else{
			range[a[i]] = ii(range[a[i]].first,i);
		}
	}
	
	for(int i=1;i<=n;i++){
		memset(used,false,sizeof(used));	
		int sum = 0;	
		int leftmost = 10000;
		for(int j=i;j>0;j--){
			leftmost = min(leftmost,range[a[j]].first);	
			if(range[a[j]].second > i ) break;
			if(!used[a[j]]){
				sum ^= a[j];
				used[a[j]] = 1;
			}
			if(leftmost == j){
				w[j][i] = sum;
			}
		}	
	}

//	for(int i=0;i<n;i++){
//		for(int j=0;j<n;j++)
//			cout << w[i][j] << ' ';
//		cout <<endl;
//	}

	for(int i=1;i<=n;i++){
		dp[i] = dp[i-1];
		for(int j=1;j<=i;j++)
			dp[i] = max(dp[i],dp[j-1]+w[j][i]);
	}

	cout << dp[n] << endl;

	return 0;
}

