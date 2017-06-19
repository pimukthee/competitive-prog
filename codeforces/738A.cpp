#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	string s,ans="";
	cin>> s;
	int i=0;
	while(i<s.length()-2 && s.length()>2){
		if(s.substr(i,3).compare("ogo")==0){
			i+=3;
			while(s.substr(i,2).compare("go")==0 && i+2<=s.length())
				i+=2;
			ans+="***";
		}
		else{
			 ans+=s[i++];
		}
	}
	cout<<ans+s.substr(i,s.length()-i)<<endl;
	return 0;
}
