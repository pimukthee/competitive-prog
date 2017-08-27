/*
Alfonso Alfonso Peterssen
19 - 3 - 2008
USACO FEB08 Silver "Game of Lines"
*/
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 200;

typedef pair< int, int > par;

int n, m, sol;
int dx, dy, gcd;
int x[MAXN], y[MAXN];
par slopes[MAXN * MAXN];

int my_gcd( int a, int b ) {
    while ( a && b ) if ( a %= b ) b %= a;
    return a + b;
}

int main() {

	while ( scanf( "%d", &n ) && n ) {
		m = 0;
    for ( int i = 0; i < n; i++ )
        scanf( "%d %d", &x[i], &y[i] );

    for ( int i = 0; i < n; i++ )
        for ( int j = 0; j < i; j++ ) {
            dx = x[i] - x[j];
            dy = y[i] - y[j];
            gcd = my_gcd( dx, dy );
            if ( gcd != 0 )
                dx /= gcd, dy /= gcd;
            slopes[m++] = make_pair( dx, dy );
        }

    sort( slopes, slopes + m );
    sol = unique( slopes, slopes + m ) - slopes;

    printf( "%d\n", sol );
}

    return 0;
}
