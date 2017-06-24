#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
struct a
{
    string str;
    int vow;
    bool operator < (const a &w) const
    {
        if(vow!=w.vow)return vow > w.vow;
        return str.compare(w.str) < 0;
    }
}arr[100010];
bool chk(int i,int j)
{
    return arr[i].str[j]=='a'||arr[i].str[j]=='e'||arr[i].str[j]=='i'||arr[i].str[j]=='o'||arr[i].str[j]=='u';
}
int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int n;
        cin >> n;
        for(int i=0; i<n; i++)
            cin >> arr[i].str;
        for(int i=0; i<n; i++)
        {
            int s = arr[i].str.length();
            arr[i].vow = chk(i,0)?1:0;
            for(int j=1; j<s; j++)
                if(chk(i,j)&&!chk(i,j-1))
                    arr[i].vow++;
        }
        sort(arr,arr+n);
        for(int i=0; i<n-1; i++)
            cout << arr[i].str << " ";
        cout << arr[n-1].str <<endl;
        for(int i=0; i<n; i++)
        {
            arr[i].str="";
            arr[i].vow = 0;
        }
    }
    return 0;
}
