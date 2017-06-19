#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

int main(){
	int n,a[6];
	string str;
	cin>>n;
	while(n!=0){
		map<string,int> mmap;
		for(int j=0;j<n;j++){
			for(int i=0;i<5;i++)
				cin>>a[i];
			sort(a,a+5);
			str = "";
			for(int i=0;i<5;i++)
				str+=to_string(a[i]);
			if(mmap[str]) mmap[str]++;
			else mmap[str]=1;
		}
		pair<int,int> mx=make_pair(0,0);
		for(auto x = mmap.begin() ; x!= mmap.end() ;x++){
//			cout<<x->first<<" " <<x->second<<endl;
			if(mx.first < x->second){
				mx = make_pair(x->second,x->second);
			}
			else if(mx.first == x->second){
				mx.second+=x->second;
			}
		}
		cout<<mx.second<<endl;
		cin>>n;
	}
}
