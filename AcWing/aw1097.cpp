//
// Created by Charry on 2022/4/25.
//

#include <iostream>
#include <queue>

using namespace std;
const int N = 1010;
char dp[N][N];
bool st[N][N];
int dir[9][2] = {{0,  0},
                 {0,  1},
                 {1,  1},
                 {1,  0},
                 {1,  -1},
                 {0,  -1},
                 {-1, -1},
                 {-1, 0},
                 {-1, 1}};//八连通,八个方向
int n, n, cnt;

void bfs(int x, int y) {
    queue<pair<int, int>> queue;
    queue.push({x, y});
    st[x][y] = true;
    while (!queue.empty()) {
        pair<int, int> cur = queue.front();
        queue.pop();
        x = cur.first;
        y = cur.second;
        st[x][y] = true;
        for (int i = 1; i <= 8; i++) {
            int xx = x + dir[i][0];
            int yy = y + dir[i][1];
            if (xx >= 1 && xx <= n && yy >= 1 && yy <= n && dp[xx][yy] == 'W' && !st[xx][yy]) {
                queue.push({xx, yy});
                st[xx][yy] = true;
            }
        }
    }
}

int main() {
    scanf("%d%d", &n, &n);
    char t[n];

    for (int i = 1; i <= n; i++) {
        scanf("%s", &t);
        for (int j = 1; j <= n; j++)
            dp[i][j] = t[j - 1];
    }//读入图

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (!st[i][j] && dp[i][j] == 'W') {
                ++cnt;
                bfs(i, j);
            }

    printf("%d", cnt);
    return 0;
}