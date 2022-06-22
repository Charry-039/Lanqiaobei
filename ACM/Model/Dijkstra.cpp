//
// Created by Charry on 2022/4/4.
//

#include <iostream>
#include <cstring>

using namespace std;

const int N = 510, M = 100010, INF = 0x3f3f3f3f;
int g[N][N], dist[N] = {INF}, st[N];
int n, m, x, y, z;

void dijkstra() {
    for (int i = 2; i <= n; i++) {
        int t = -1;
        for (int j = 1; j <= n; j++)
            if ((t == -1 || dist[j] < dist[t]) && !st[j])
                t = j;
        st[t] = true;
        for (int j = 1; j <= n; j++)
            dist[j] = min(dist[j], dist[t] + g[t][j]);
    }
}

int main() {
    scanf("%d%d", &n, &m);
    while (m--) {
        scanf("%d%d%d", &x, &y, &z);
        g[x][y] = min(g[x][y], z);
    }
    memset(dist, INF, sizeof dist);
    for (int i = 1; i <= n; i++)
        g[i][i] = 0;
    dist[1] = 0;
    dijkstra();
    printf("%d", dist[n] == INF ? -1 : dist[n]);
}
