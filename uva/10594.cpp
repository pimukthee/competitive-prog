//=============================//
// Author: LAM PHAN VIET       //
// Online Judge: UVA
// Problem: 10594 - Data Flow
// Time limit: 3.000s
//=============================//
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define inpFile(f) freopen(f, "r", stdin)
#define outFile(f) freopen(f, "w", stdout)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define REP(i, n) for (int i = 0; i < n; i++)
#define fill(ar, val) memset(ar, val, sizeof(ar))
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define ff first
#define ss second
#define bit(n) (1<<(n))
#define Last(i) ( i & -i )
#define INF 500000000
#define maxN 105
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int n, capa, data, trace[maxN], c[maxN][maxN], f[maxN][maxN];
int64 timeCost[maxN][maxN], d[maxN], sumTime;
bool inQueue[maxN];

bool findPath()   // FordBellman + Queue  time: 0.164
{
    FOR (i, 1, n)
    d[i] = INF, trace[i] = 0, inQueue[i] = false;
    queue<int> Q;
    Q.push(1);
    d[1] = 0;
    inQueue[1] = true;
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        inQueue[u] = false;
        FOR (v, 1, n)
        if (c[u][v] > f[u][v] && d[u] + timeCost[u][v] < d[v])
        {
            d[v] = d[u] + timeCost[u][v];
            trace[v] = u;
            if (!inQueue[v])
            {
                Q.push(v);
                inQueue[v] = true;
            }
        }
    }
    return trace[n];
}

void incFlow()
{
    int delta = INF, u, v;
    v = n;
    do
    {
        u = trace[v];
        delta = min(delta, c[u][v] - f[u][v]);
        v = u;
    }
    while (v != 1);
    v = n;
    do
    {
        u = trace[v];
        c[u][v] -= delta;
        c[v][u] += delta;
        timeCost[v][u] = -timeCost[v][u];
        timeCost[u][v] = -timeCost[u][v];
        v = u;
    }
    while (v != 1);
    int sent = min(data, capa);
    data -= sent;
    sumTime += (int64)sent * d[n];
}

main()
{
    int m, u, v;
    while (scanf("%d %d", &n, &m) != EOF)
    {
        FOR (i, 1, n) FOR (j, 1, n)
        timeCost[i][j] = INF;
        while (m--)
        {
            scanf("%d %d", &u, &v);
            scanf("%lld", &timeCost[u][v]);
            timeCost[v][u] = timeCost[u][v];
        }
        scanf("%d %d", &data, &capa);
        FOR (i, 1, n) FOR (j, 1, n)
        c[i][j] = c[j][i] = capa;
        sumTime = 0;
        while (data && findPath()) {
            incFlow();
            cout << sumTime << endl;
        }
        cout << d[n];
        do {
            n = trace[n];
            cout << " " << n;
        } while (n != 1);
        if (data) puts("Impossible.");
        else printf("%lld\n", sumTime);
    }
}

