#include <iostream>
#include <cstdio>
#include <cstring>
#include <utility>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

template <typename T>
using pql = priority_queue<T, vector<T>, greater<T> >; 
template <typename T>
using pqm = priority_queue<T>;

#define INF 1e9
#define mp make_pair
#define push_back pb

int main(){
	
	int n;
	cin >> n;
	int dp[n+1],num[n+1];

	memset(dp,0,sizeof(dp));

	for(int i=1;i<=n;i++)
		cin >> num[i];

	// dp best between ch
	for(int i=1;i<=n;i++){
		dp[i] = max(num[i],dp[i-1]+num[i]);	
	}

	cout << dp[n] <<endl;
	
	return 0;

}
