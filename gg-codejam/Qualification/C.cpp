#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int T,c=0;
    cin >> T;
    long long N,K,p,high,l,r,f,odd,even,todd,teven;
    long long tempOdd,tempEven,rtempOdd,rtempEven;
    while(c++<T){
        cin >> N >> K;
        p = 1LL;
        odd = even = 0LL;
        tempOdd = tempEven = 0LL;
        if(N%2LL==0LL) even=1LL,tempEven = N;
        else odd=1LL,tempOdd = N;

        while(p*2LL <= K){
            todd = 0LL;
            teven = 0LL;
            rtempOdd = tempOdd;
            rtempEven = tempEven;
            p*=2LL;
            if(odd){
                if((tempOdd/2LL)%2LL==0LL){
                    teven += odd*2LL;
                    rtempEven = tempOdd / 2LL;
                }
                else {
                    todd += odd*2LL;
                    rtempOdd = tempOdd/2LL;
                }
            }

            if(even){
                todd += even;
                teven += even;
                if((tempEven/2LL)%2LL==0LL){
                    rtempOdd =  tempEven/2LL-1LL;
                    rtempEven = tempEven/2LL;
                }
                else{
                    rtempOdd =  tempEven/2LL;
                    rtempEven = tempEven/2LL-1LL;
                }
            }
            odd = todd;
            even = teven;
            tempOdd = rtempOdd;
            tempEven = rtempEven;

        }

        if(odd>0LL && even>0LL){
            if(tempOdd>tempEven){
                if(K-p < odd) N = tempOdd;
                else N = tempEven;
            }
            else{
                if(K-p < even) N =tempEven;
                else N = tempOdd;
            }
        }
        else if(odd>0LL)N = tempOdd;
        else N = tempEven;

        if(N%2LL == 0LL){
            l = N/2LL;
            r = (N-1LL)/2LL;
        }
        else l=r=N/2LL;

        printf("Case #%d: %lld %lld\n",c,max(l,r),min(l,r));
    }

    return 0;
}
