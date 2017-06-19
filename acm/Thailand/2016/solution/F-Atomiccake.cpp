#include<iostream>
#include<vector>
using namespace std;

int main(){
	int t;
	cin >> t;
	for(;t>0;t--){
		int n;
		cin >> n;
		if(n==0){
			cout << "n\n";
			continue;
		}
		int neg=0;
		if(n<0){
			neg = 1;
			n = -n;
		}
		vector<char> v;
		while(n>0){
			if(n%2==0){
				v.push_back('n');
			}
			else if(n%4==1){
				if(neg==1) v.push_back('e');
				else v.push_back('p');
			}
			else{
				n++;
				if(neg==1) v.push_back('p');
				else v.push_back('e');
			}
			n/=2;
		}
		for(int i=v.size()-1;i>=0;i--)
			cout << v[i];
		cout << "\n";
	}
	return 0;
}
