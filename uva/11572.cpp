#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main(){
	int t,C,n;
	cin>>C;
	while(C--){
		cin>>n;
		int mx = 0;
		map<int,int> mmap;
		for(int i=0;i<n;i++){
			cin>>t;
			auto x = mmap.find(t);
			if(x==mmap.end()) mmap[t]=i;
			else{
				mx = max(mx,(int)mmap.size());	
				int p = x->second;
				for(auto e = --mmap.end() ; e!=mmap.begin() ; e--){
					if(e->second <= p) mmap.erase(e);
				}
				if(mmap.begin()->second <= p ) mmap.erase(mmap.begin());
				mmap[t]=i;
			}
		}
		mx = max(mx,(int)mmap.size());
		cout<<mx<<endl;
	}
	cout<<endl;
	return 0;
}
