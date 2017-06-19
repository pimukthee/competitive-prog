#include <iostream>
using namespace std;
int main()
{
    long long A,B,ans=0;
    cin >> A >> B ;
    while(A > 0) {
		ans += B / A;
		B %= A;
		swap(A, B);
	}
	cout << ans ;
    return 0;
}
