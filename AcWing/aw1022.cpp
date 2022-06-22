//
// Created by Charry on 2022/5/19.
//

#include "iostream"
#include "cstring"

using namespace std;
const int N = 1010;
int dp[N];
int spend[N], damage[N];
int n, m, k, cnt;

int main() {
    memset(dp, 0x3f3f3f3f, sizeof dp);
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= k; i++) {
        scanf("%d%d", &spend[i], &damage[i]);
        for (int j = n; j >= spend[i]; j--)
            if (dp[j - spend[i]] + damage[i] < dp[j]) {
                ++cnt;
                dp[j] = dp[j - spend[i] + damage[i]];
            }
    }
//    printf("%d %d\n", cnt, dp[]);
    return 0;
}