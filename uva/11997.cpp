#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main(){
	int n,d[755][755],index[755];
	bool chk=false;
	while(cin>>n){
		memset(index,0,sizeof index);
		if(chk) cout<<endl,chk=true;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin>>d[i][j];
			}
		}
		for(int i=0;i<n;i++)
			sort(d[i],d[i]+n);

		long temp,ans=0;
		int p;

		for(int i=0;i<n;i++){
			ans+=d[i][0];			
		}
		cout<<ans;
		for(int i=1;i<n;i++){
			cout<<" ";
			temp= ans - d[0][index[0]] + d[0][index[0]+1];
			index[0]++;
			p=0;
			cout<<temp<<"*";
			for(int j=1;j<n;j++){
				if(ans - d[j][index[j]] + d[j][index[j]+1] <= temp){
					index[p]--;
					temp = ans - d[j][index[j]] + d[j][index[j]+1];
					index[j]++;
					p = j; 
				}
			}
			ans = temp;
			cout<<ans;
		}
	}
	return 0;
}
