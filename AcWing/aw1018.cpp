//
// Created by Charry on 2022/4/27.
//

#include "iostream"
#include "cstring"

using namespace std;
const int N = 110;
int w[N][N];
int dp[N][N];
int n;

int main() {
    scanf("%d", &n);
    memset(dp, 0x3f3f3f, sizeof dp);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &w[i][j]);

    dp[1][1] = w[1][1];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            dp[i][j] = min(min(dp[i][j], dp[i - 1][j] + w[i][j]), min(dp[i][j], dp[i][j - 1] + w[i][j]));

    printf("%d", dp[n][n]);
    return 0;
}