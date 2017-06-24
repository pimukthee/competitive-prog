#include <map>
#include <string>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    string line;
    vector<int> all_integers;
    while ( getline( cin, line ) )
    {
        all_integers.clear();
        istringstream is( line );
        int val;
        while(is>>val)
        {
            all_integers.push_back(val);
        }
        for(int i=0; i<all_integers.size(); i++)
        printf("%d ",all_integers[i]);
    }

    return 0;
}
