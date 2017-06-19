#include <iostream>
#include <string>
#include <vector>

using namespace std;

class UnionFind{
	private:
		vector<int> p,rank,nsize;
	public:
		UnionFind(int n){
			n+=10;
			rank.assign(n,0);
			nsize.assign(n,1);
			p.assign(n,0);
			for(int i=0;i<n;i++) p[i]=i;
		}
		int findHead(int a){
			if(a==p[a]) return a;
			else return p[a] = findHead(p[a]);
		}
		void unionSet(int a,int b){
			int ha = findHead(a);
			int hb = findHead(b);
			if(ha!=hb){
				if(rank[ha]<rank[hb]) p[ha]=hb,nsize[hb]+=nsize[ha];
				else if(rank[ha]>rank[ha]) p[hb]=ha,nsize[ha]+=nsize[hb];
				else p[ha]=hb,rank[hb]++,nsize[hb]+=nsize[ha];
			}
		}
		bool isSameSet(int a,int b){
			return findHead(a) == findHead(b);
		}
		int size(int n){
			return nsize[n];
		}
};

int main(){
	vector<int> adj[30];
	vector<bool> exist;
	int n,q;
	string s;
	char a,b;
	int y=0;
	while(cin >> n >> q){
		UnionFind u(30);
		exist.assign(30,false);
		for(int i=0;i<30;i++)adj[i].clear();
		cin >> s;
		y=0;		
		for(int i=1;i<s.length();i++) u.unionSet(s[i-1]-'A',s[i]-'A');
		for(int i=0;i<s.length();i++) exist[s[i]-'A']=1;

		for(int i=0;i<q;i++){
			cin >> a >> b;	
			adj[a-'A'].push_back(b-'A');
			adj[b-'A'].push_back(a-'A');
			exist[a-'A'] = 1;
			exist[b-'A'] = 1;
		}

		string ans="";
		if(u.size(u.findHead(s[0]-'A')) == n)
			ans = "WAKE UP IN, "+to_string(y)+", YEARS";
		while(ans==""){
			y++;
			vector<int> append;
			for(int i=0;i<26;i++){
				if(!exist[i]) continue;
				if(u.isSameSet(i,s[0]-'A')) continue;
				int connect=0;
				for(int e : adj[i]){
					if(u.isSameSet(e,s[0]-'A')) connect++;
				}
				if(connect>=3)append.push_back(i); 
			}
			for(int e:append) u.unionSet(e,s[0]-'A');

			if(append.empty())
				ans = "THIS BRAIN NEVER WAKES UP";
			
			if(u.size(u.findHead(s[0]-'A')) == n)
				ans = "WAKE UP IN, "+to_string(y)+", YEARS";
		}
		cout << ans <<endl;
	}
}
