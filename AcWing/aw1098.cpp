//
// Created by Charry on 2022/4/27.
//

#include <iostream>
#include "queue"

using namespace std;
const int N = 51;
int g[N][N];
bool st[N][N];
int n, cnt, maxn;

int bfs(int x, int y) {
    int s = 0;
    int dir[5][2] = {{0,  0},
                     {0,  1},
                     {1,  0},
                     {0,  -1},
                     {-1, 0}};
    queue<pair<int, int>> q;
    q.push({x, y});
    st[x][y] = true;
    while (!q.empty()) {
        pair<int, int> t = q.front();
        q.pop();
        ++s;
        x = t.first;
        y = t.second;
        for (int i = 1; i <= 4; i++) {
            int xx = x + dir[i][0];
            int yy = y + dir[i][1];
            if (xx >= 1 && xx <= n && yy >= 1 && yy <= n && !st[xx][yy] && !((g[xx][yy] >> (i - 1)) & 1)) {
                q.push({xx, yy});
                st[xx][yy] = true;
            }
        }
    }
    return s;
}

int main() {
    scanf("%d%d", &n, &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &g[i][j]);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (!st[i][j]) {
                ++cnt;
                maxn = max(maxn, bfs(i, j));
            }

    printf("%d\n%d", cnt, maxn);
    return 0;
}