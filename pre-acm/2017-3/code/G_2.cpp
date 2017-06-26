#include <bits/stdc++.h>
using namespace std;


#define NN 105

long long cap[NN][NN];
long long cost[NN][NN];
long long fnet[NN][NN], d[NN];
vector <int> adj[NN];

int par[NN]; // par[source] = source;

// Labelling function
long long pi[NN];

#define Inf 1000000000

// Dijkstra's using non-negative edge weights (cost + potential)
#define Pot(u, v) (d[u] + pi[u] - pi[v])
bool dijkstra(int n, int s, int t)
{
    for (int i = 1; i <= n; i++)
        d[i] = Inf, par[i] = -1;
    d[s] = 0;
    par[s] = -n - 1;

    while (1)
    {
        // find u with smallest d[u]
        int u = -1, bestD = Inf;
        for (int i = 1; i <= n; i++)
            if (par[i] < 0 && d[i] < bestD) {
                bestD = d[i];
                u = i;
            }
        if (bestD == Inf)
            break;

        // relax edge (u,i) or (i,u) for all i;
        par[u] = -par[u] - 1;
        for (int v : adj[u])
        {
            // try undoing edge v->u
            if (par[v] >= 0)
                continue;
            if (fnet[v][u] && d[v] > d[u] - cost[v][u])
                d[v] = d[u] - cost[v][u], par[v] = -u - 1;

            // try edge u->v
            if (fnet[u][v] < cap[u][v] && d[v] > Pot(u, v) + cost[u][v])
                d[v] = d[u] + cost[u][v], par[v] = -u - 1;
        }
    }

    for (int i = 1; i <= n; i++)
        if (pi[i] < Inf)
            pi[i] += d[i];

    return par[t] >= 0;
}
#undef Pot

void mcmf3(int n, int s, int t, long long &fcost, int& flow)
{
    // build the adjacency list
    fcost = 0;

    // repeatedly, find a cheapest path from s to t
    while (dijkstra(n, s, t) && flow > 0)
    {
        // get the bottleneck capacity
        long long bot = Inf;
        for (int v = t, u = par[v]; v != s; u = par[v]) {
            bot = min(bot, fnet[v][u] ? fnet[v][u] : (cap[u][v] - fnet[u][v]));
           // cout << u << endl;
            v = u;
        }
        printf ("%d ", n);
        for (int v = t, u = par[v]; v != s; u = par[v]) {
            printf ("%d ", u);
            if (fnet[v][u]) {
                fnet[v][u] -= bot;
                fcost -= bot * cost[v][u];
            } else {
                fnet[u][v] += bot;
                fcost += bot * cost[u][v];
            }
            v = u;
        }
        printf("\n");
        flow -= bot;
    }

}

int main()
{
    int n;
    int m, a, b;
    long long c, cp;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %lld %lld", &a, &b, &cp, &c);
        cost[a][b] = c;  
        cost[b][a] = c;
        cap[a][b] = cp;  
        cap[b][a] = cp;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int flow;
    long long fcost = 0;
    scanf("%d", &flow);
    mcmf3(n, 1, n, fcost, flow);
    if (flow > 0) printf("NO");
    else printf("%lld", fcost);

    return 0;
}