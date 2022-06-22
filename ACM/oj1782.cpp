//
// Created by Charry on 2022/3/28.
//
#include <iostream>
using namespace std;

const int N = 15, inf = 9999;
int dp[N][N];
int n1, n;

void floyd() {
    for (int k = 1; k < N; k++)
        for (int i = 1; i < N; i++)
            for (int j = 1; j < N; j++)
                dp[i][j] = min(dp[i][k] + dp[k][j], dp[i][j]);
}

void init() {
    for (int i = 1; i < N; i++)
        for (int j = 1; j < N; j++)
            dp[i][j] = (i == j ? 0 : inf);
}

int main() {
    scanf("%d%d", &n1, &n);
    init();
    while (n--) {
        int x, y, l;
        scanf("%d%d%d", &x, &y, &l);
        dp[x][y] = dp[y][x] = l;
    }
    floyd();
    int x, y;
    scanf("%d%d", &x, &y);
    if (dp[x][y] == inf) cout << "No path";
    else cout << dp[x][y];
}
