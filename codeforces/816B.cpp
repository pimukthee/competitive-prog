#include <iostream>
#include <cstdio>
#include <cstring>
#include <utility>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <cmath>
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
#define PI 3.141592653589793238

long long mem[200000+10];
long long dp[200000+10];

int main(){
	int n,k,q,l,r;
	cin >> n >> k >> q;
	for(int i=0;i<n;i++){
		scanf("%d %d",&l,&r);
		mem[l]++;
		mem[r+1]--;	
	}
	int count =0;
	for(int i=1;i<=200000;i++){
		mem[i] = mem[i-1] + mem[i];
		dp[i] = dp[i-1] +(mem[i]>=k ? 1LL : 0LL);
	}
	for(int i=0;i<q;i++){
		scanf("%d %d",&l,&r);
		printf("%I64d\n",dp[r]-dp[l-1]);
	}
//	for(int i=90;i<100;i++)
//		cout << mem[i] << ' ';
//	cout<<endl;
//	for(int i=90;i<100;i++)
//		cout << dp[i] << ' ';
	return 0;
}
