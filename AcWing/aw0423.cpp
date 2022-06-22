//
// Created by Charry on 2022/5/19.
//

#include "iostream"

using namespace std;
const int N = 1010;
int Time[N];
int w[N];
int dp[N];

int main() {
    int t, m;
    scanf("%d%d", &t, &m);
    for (int i = 1; i <= m; i++)
        scanf("\n%d%d", &Time[i], &w[i]);
    for (int i = 1; i <= m; i++)
        for (int j = t; j >= Time[i]; j--)
            dp[j] = max(dp[j], dp[j - Time[i]] + w[i]);

    printf("%d\n", dp[t]);
    return 0;
}