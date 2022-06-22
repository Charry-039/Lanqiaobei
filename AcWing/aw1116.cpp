//
// Created by Charry on 2022/5/14.
//

#include "iostream"
#include "queue"
#include "cstring"

using namespace std;
typedef pair<int,int> PII;
const int N = 10;
int g[N][N];
bool st[N][N];
int dx[] = {0, -2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {0, 1, 2, 2, 1, -1, -2, -2, 1};
int n, m, sx, sy;

int bfs(){
    queue<PII>q;
    q.push({sx, sy});
    st[sx][sy]=true;
    while (!q.empty()){
        PII t=q.front();
    }
}

int main() {
    int t;
    scanf("%d\n", &t);
    while (t--) {
        memset(g, 0, sizeof g);
        memset(st, false, sizeof st);
        scanf("%d%d%d%d\n", &n, &m, &sx, &sy);
        printf("%d\n",bfs());
    }
    return 0;
}