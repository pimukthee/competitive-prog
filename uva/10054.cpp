
#include <iostream>
#include <vector>

using namespace std;

int bead[1111][1111];
int T;
int N;
int a,b;
int x,y;
vector<int> ans;
void clear() {
    for(int i = 0 ; i < 51 ; i++) {
        for (int j = 0 ; j < 51; j++) {
            bead[i][j] = 0;
        }
    }
}

void dfs(int s) {
    for(int d = 0 ; d < 51 ; d ++) {
        if(bead[s][d]>0) {
            bead[s][d]--;
            bead[d][s]--;
            dfs(d);
        }
    }
    ans.push_back(s);
}

void process(int first_color){
    // Euler Check
    int cnt;
    for(int i = 0 ; i < 51 ; i++ ) {
        cnt = 0;
        for( int j = 0 ; j < 51 ; j++) {
            cnt += bead[i][j];
        }
        if(cnt%2!=0) {
            printf("some beads may be lost\n");
            return;
        }
    }

    dfs(x);

    for(int i = 0; i < ans.size()-1; i++ ) {
        printf("%d %d\n", ans[i], ans[i+1]);
    }

}



int main(int argc, const char * argv[]) {

    scanf("%d", &T);

    for(int tc=1;tc<=T;tc++) {
        scanf("%d", &N);
        clear();
        for (int i=0;i<N;i++) {
            cin >> a >> b;
            bead[a][b]++;
            bead[b][a]++;
            x = a;
        }
        if(tc!=1) putchar('\n');
        printf("Case #%d\n", tc);
        ans.clear();
        process(x);
    }


    return 0;
}
