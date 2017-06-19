#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> num;
int arr[100005];
int main()
{
    int ans=1,n,k;
    scanf("%d%d",&n,&k);
    for(int i=0; i<n; i++)
        scanf("%d",&arr[i]);
    sort(arr,arr+n);
    for(int i=0; i<n; i++)
    {
        if(arr[i]%k!=0)

            num.push_back(arr[i]);
        else
        {
            if(!binary_search(num.begin(),num.end(),arr[i]/k))
                num.push_back(arr[i]);
        }
    }
    printf("%d",num.size());
    return 0;
}
