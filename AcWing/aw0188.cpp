//
// Created by Charry on 2022/5/12.
//

#include "iostream"
#include "queue"

using namespace std;
typedef pair<int, int> pii;

const int N = 155;
char g[N][N];
int step[N][N];
int dx[] = {0, -2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {0, 1, 2, 2, 1, -1, -2, -2, -1};
bool st[N][N];
int r, c, sx, sy, ex, ey;

void bfs() {
    queue<pii> q;
    q.push({sx, sy});
    st[sx][sy] = true;
    while (q.size()) {
        pii t = q.front();
        q.pop();
        int x = t.first;
        int y = t.second;
        if (x == ex && y == ey) break;
        for (int i = 1; i <= 8; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx >= 1 && xx <= r && yy >= 1 && yy <= c && !st[xx][yy] && g[xx][yy] != '*') {
                q.push({xx, yy});
                st[xx][yy] = true;
                step[xx][yy] = step[x][y] + 1;
            }
        }
    }
}

int main() {
    scanf("%d%d", &c, &r);
    for (int i = 1; i <= r; i++) {
        scanf("\n");
        for (int j = 1; j <= c; j++) {
            scanf("%c", &g[i][j]);
            if (g[i][j] == 'K')sx = i, sy = j;
            else if (g[i][j] == 'H')ex = i, ey = j;
        }
    }

    bfs();
    printf("%d\n", step[ex][ey]);
    return 0;
}