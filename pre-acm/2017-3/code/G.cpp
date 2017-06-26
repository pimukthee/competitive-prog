#include <bits/stdc++.h>

using namespace std;

#define INF 500000000
#define maxN 105

int n, k, path[maxN];
long long cost[maxN][maxN], d[maxN], ans, capa[maxN][maxN];
bool visit[maxN];

bool find_path()
{
    for (int i = 1; i <= n; ++i) {
        d[i] = INF;
        path[i] = 0;
        visit[i] = false;
    }
    queue<int> q;
    q.push(1);
    d[1] = 0;
    visit[1] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        visit[u] = false;
        for (int i = 1; i <= n; ++i) {
            if (capa[u][i] > 0 && d[u] + cost[u][i] < d[i]) {
                d[i] = d[u] + cost[u][i];
                path[i] = u;
                if (!visit[i]) {
                    q.push(i);
                    visit[i] = true;
                }
            }
        }
    }

    return path[n];
}

void max_flow()
{
    int u, v;
    long long sent = INF;
    v = n;
    do {
        u = path[v];
        sent = min(sent, capa[u][v]);
        v = u;
    } while (v != 1);
    v = n;
    do {
        u = path[v];
        capa[u][v] -= sent;
        capa[v][u] += sent;
        cost[v][u] = -cost[v][u];
        cost[u][v] = -cost[u][v];
        v = u;
    } while (v != 1);
    k -= sent;
    ans += sent * d[n];
}
int main()
{
    int m, u, v;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) cost[i][j] = INF;
    while (m--) {
        scanf("%d %d", &u, &v);
        scanf("%lld %lld", &capa[u][v], &cost[u][v]);
        cost[v][u] = cost[u][v];
        capa[v][u] = capa[u][v];
    }

   /* for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << capa[i][j] << " ";
        }
        cout << endl;
    }*/

    scanf("%d", &k);

    ans = 0;
    while (k && find_path()) max_flow();

    /*cout << n ;
    do {
        n = path[n];
        cout << " " << n;
    } while (n != 1);*/

    if (k) printf("NO\n");
    else printf("%lld\n", ans);

    return 0;
}
