#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    string str = "";
    
    cin >> n;
   
    for (int i = 1; i <= 1000; ++i) str += to_string(i);

    cout << str[n - 1] << endl;

    return 0;
}