#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main(){
    int SET,n,s,Q,m,t,cargoes;
    int time,station;
    cin >> SET;
    while(SET--){
        deque<int> q[101];
        stack<int> carrier;
        time =0;
        station = 0;
        cargoes = 0;
        cin >> n >> s >> Q;
        for(int i=0;i<n;i++){
            cin >> m;
            cargoes += m;
            while(m--){
                cin >> t;
                q[i].push_back(t);
            }
        }

        while(true){
          //  cout << station <<' ' << cargoes << endl;

            while(!carrier.empty()){
                if(carrier.top()==station+1) cargoes--;
                else if(q[station].size()<Q)
                    q[station].push_back(carrier.top());
                else break;
                carrier.pop();
                time++;
            }
            while(carrier.size()<s && !q[station].empty()){
                carrier.push(q[station].front());
                q[station].pop_front();
                time++;
            }
            if(cargoes<=0) break;
            time+=2;
            station = (station+1)%n;
        }
        cout << time << endl;
    }
    return 0;
}
