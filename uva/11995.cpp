#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int main(){
    int n,a,x;
    while(cin>>n){
        queue<int>q;
        stack<int>st;
        priority_queue<int>pq;
        bool isq,isst,ispq;
        isq = isst = ispq =true;
        for(int i=0;i<n;i++){
            cin >> a >> x;
            if(a == 1){
                q.push(x);
                pq.push(x);
                st.push(x);
            }
            else if(a==2){
                if(!q.empty() && q.front()==x )q.pop();
                else isq = false;
                if(!pq.empty() && pq.top()==x ) pq.pop();
                else ispq = false;
                if(!st.empty() && st.top() ==x ) st.pop();
                else isst = false;
             }

        }
        if(!ispq && !isst && isq) cout<<"queue"<<endl;
        else if(!ispq && isst && !isq) cout<<"stack"<<endl;
        else if(ispq && !isst && !isq) cout<<"priority queue"<<endl;
        else if(ispq || isst || isq) cout<<"not sure"<<endl;
        else if(!ispq && !isst && !isq) cout<<"impossible"<<endl;

    }
    return 0;
}
