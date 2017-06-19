#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n,t,x[10000],ans;
	cin>>n;
	while(n>0){
		cin>>ans;
		for(int i=1;i<n;i++){
			cin>>x[i];
		}
		ans = t = x[0];	
		for(int i=1;i<n;i++){
			if(x[i] > t+x[i] ) t = x[i];
			else t+=x[i];
			ans = max(ans,t);	
		}
		if(ans>0) cout<<"The maximum winning streak is "<<ans<<".";
		else cout<<"Losing streak.";
		cout<<endl;
		cin>>n;
	}
	return 0;
}
