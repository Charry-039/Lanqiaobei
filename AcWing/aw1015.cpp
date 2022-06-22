//
// Created by Charry on 2022/4/27.
//

#include "iostream"
#include "cstring"

using namespace std;

int main() {
    int t, r, c;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &r, &c);
        int dp[r + 1][c + 1];
        memset(dp, 0, sizeof dp);
        for (int i = 1; i <= r; i++)
            for (int j = 1; j <= c; j++)
                scanf("%d", &dp[i][j]);

        for (int i = 1; i <= r; i++)
            for (int j = 1; j <= c; j++)
                dp[i][j] += max(dp[i - 1][j], dp[i][j - 1]);

        printf("%d\n", dp[r][c]);
    }
    return 0;
}