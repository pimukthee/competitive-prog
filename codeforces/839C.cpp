#include <bits/stdc++.h>

#define mp make_pair

using namespace std;

queue <pair<double, pair<int,int>> > bfs;
vector <int> adj[100010];
bool visited[100010], has_next;

int main() {
    double ans = 0;
    int n, u, v, way = 0, total_distance = 0;
    scanf("%d", &n);

    for (int i = 1; i < n; ++i) {
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    visited[1] = true;
    for (int i : adj[1]) bfs.push(mp(1.0/adj[1].size(), mp(i, 1)));
    while (!bfs.empty()) {
        double prob = bfs.front().first;
        int cur = bfs.front().second.first;
        int dis = bfs.front().second.second;
        bfs.pop();
        visited[cur] = true;
        has_next = false;
        for (int i : adj[cur]) {
            if (!visited[i]) {
                has_next = true;
                bfs.push(mp(prob/(1.0*(adj[cur].size()-1)), mp(i, dis + 1)));
            }
        }

        if (!has_next) ans += 1.0*dis*prob;

    }

    printf("%.10f", ans);

    return 0;
}
