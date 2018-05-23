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
