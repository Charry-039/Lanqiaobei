#include "iostream"
#include "queue"

using namespace std;
typedef pair<int, int> PII;
const int N = 1010;
PII memory[N][N];
int g[N][N];
bool st[N][N];
int n;

void bfs() {
    queue<PII> q;
    q.push({n - 1, n - 1});
    st[n - 1][n - 1] = true;
    int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
    while (q.size()) {
        PII t = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int x = t.first + dx[i];
            int y = t.second + dy[i];
            if (x >= 0 && x < n && y >= 0 && y < n && !st[x][y] && !g[x][y]) {
                q.push({x, y});
                memory[x][y] = t;
                st[x][y] = true;
            }
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &g[i][j]);
    bfs();
    PII t = {0, 0};
    printf("%d %d\n", 0, 0);
    while (t.first != n - 1 || t.second != n - 1) {
        printf("%d %d\n", memory[t.first][t.second].first, memory[t.first][t.second].second);
        t = memory[t.first][t.second];
    }
    return 0;
}