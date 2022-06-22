//
// Created by Charry on 2022/4/24.
//

#include <iostream>

using namespace std;
const int N = 5100;
int dp[N][N];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    m = min(m, 5001);
    int x, y, w;
    while (n--) {
        scanf("%d%d%d", &x, &y, &w);
        ++x;
        ++y;//预处理，坐标从1开始
        dp[x][y] += w;
    }
    for (int i = 1; i <= 5001; i++)
        for (int j = 1; j <= 5001; j++)
            dp[i][j] += dp[i - 1][j] + dp[i][j - 1] + dp[i - 1][j - 1];//求二维前缀和dsada

    int res = 0;
    for (int i = m; i <= 5001; i++)
        for (int j = m; j <= 5001; j++)
            res = max(res, dp[i][j] - dp[i - m][j] - dp[i][j - m] + dp[i - m][j - m]);//m*m范围内找最大前缀和
    printf("%d", res);
    return 0;
}