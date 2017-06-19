#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <utility>
#include <set>
#include <math.h>
#define pi acos(-1.0)
#define N 1000000
using namespace std;

int n;
int a [20];
bool available [20];
int isPrime [42] = {0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0,
                    1, 0, 1, 0, 0, 0, 1, 0, 1, 0,
                    0, 0, 1, 0, 0, 0, 0, 0, 1, 0,
                    1, 0, 0, 0, 0, 0, 1, 0, 0, 0,
                    1};

bool valid (int num, int in)
{
    if ( in == n - 1 ) {
        if (isPrime [a [in - 1] + num] && isPrime [num + 1])
            return true;
        return false;
    }
    return isPrime [a [in - 1] + num];
}

void bktk (int index)
{
    if ( index == n ) {
        printf ("%d", a [0]);
        for ( int i = 1; i < n; i++ )
            printf (" %d", a [i]);
        printf ("\n");
        return;
    }

    for ( int i = 2; i <= n; i++ ) {
        if ( available [i] ) {
            if ( valid (i, index) ) {
                available [i] = false;
                a [index] = i;
                bktk (index + 1);
                available [i] = true;
            }
        }
    }
}

int main ()
{
    int cases = 0;

    while ( scanf ("%d", &n) != EOF ) {
        a [0] = 1;
        if(cases) printf("\n");
        printf ("Case %d:\n", ++cases);
        memset (available, true, sizeof (available));

        bktk (1);
        //printf ("\n");
    }

    return 0;
}
