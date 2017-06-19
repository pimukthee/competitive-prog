#include <iostream>
#include <vector>
using namespace std;
int main()
{
    string s;
    vector <char> st;
    cin >> s;
    int n = s.length();
    for(int i=0; i<n; i++)
    {
        if(st.empty() || st.back()!=s[i])
            st.push_back(s[i]);
        else
            st.pop_back();
    }
    n = st.size();
    for(int i=0; i<n; i++)
        cout << st[i];
    return 0;
}
