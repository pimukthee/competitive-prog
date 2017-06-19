#include <iostream>
#include <string>

using namespace std;

string temp[7] = {"2-1*3","3-2+1","3-2*1","3-2-1","2-3*1","2-3-1","1-2*3"};

string f(int n,int z){
//    cout << n << ' ' << z <<endl;
    if(n==3){
        if(z==3) return temp[0];
        else if(z==2) return temp[1];
        else if(z==1) return temp[2];
        else if(z==0) return temp[3];
        else if(z==-1) return temp[4];
        else if(z==-2) return temp[5];
        else if(z==-3) return temp[6];
    }
    else{

        if(z<0) return f(n-1,n+z)+"-"+to_string(n);
        else if(z==0) return f(n-1,0)+"*"+to_string(n);
        else return f(n-1,z-n)+"+"+to_string(n);
    }
}

int main(){
    int n,x;
    cin >> n >> x;
    if(n==2){
        if(x==1) cout << "2-1"<<endl;
        else cout << "2*1" <<endl;
    }
    else{
        cout<<f(n,x)<<endl;;
    }

    return 0;
}
