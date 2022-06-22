#include "iostream"
#include "queue"

using namespace std;

typedef pair<int, int> PII;

const int N = 1010;
int g[N][N];
int dir[9][2] = {{0,  0},
                 {0,  1},
                 {1,  1},
                 {1,  0},
                 {1,  -1},
                 {0,  -1},
                 {-1, -1},
                 {-1, 0},
                 {-1, 1}};
int n, peak, valley;
bool st[N][N];
bool has_lower, has_higher;

void bfs(int x, int y) {
    queue<PII> queue;
    queue.push({x, y});
    st[x][y] = true;
    while (!queue.empty()) {
        PII t = queue.front();
        queue.pop();
        x = t.first;
        y = t.second;
        for (int i = 1; i <= 8; i++) {
            int xx = x + dir[i][0];
            int yy = y + dir[i][1];
            if (xx < 1 | xx > n || yy < 1 || yy > n)continue;
            if (g[x][y] != g[xx][yy]) {
                if (g[x][y] > g[xx][yy]) has_lower = true;
                else has_higher = true;
            } else if (!st[xx][yy]) {
                queue.push({xx, yy});
                st[xx][yy] = true;
            }
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &g[i][j]);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (!st[i][j]) {
                has_lower = false;
                has_higher = false;
                bfs(i, j);
                if (!has_lower) ++valley;
                if (!has_higher) ++peak;
            }

    printf("%d %d", peak, valley);
}