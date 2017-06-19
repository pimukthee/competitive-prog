#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main(){
	string str;
	cin>>str;
	int Case=1;
	bool isAppend;
	while(str.compare("end")!=0){
		vector<int> v;
		for(int i=0;i<str.length();i++){
			isAppend = false;
			for(auto x = v.begin(); x!=v.end(); x++){
				if(str.at(i)<=*x){
					isAppend = true;
					*x = str.at(i);
					break;
				}
			}
			if(!isAppend) v.push_back(str.at(i));
		}		
		cout<<"Case "<<Case++<<": "<<v.size()<<endl;
		cin>>str;
	}

}
