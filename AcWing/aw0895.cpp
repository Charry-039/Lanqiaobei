//
// Created by Charry on 2022/4/28.
//

#include <iostream>

using namespace std;
const int N = 1010;
int w[N];
int dp[N];
int n, ans = 0;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &w[i]);//存储第i个数的值

    for (int i = 1; i <= n; i++){
        dp[i]=1;//memset()只能将数组初始化为-1或0，无法初始化为1，故在for里初始化
        for (int j = 1; j <= i; j++) //每个第i个数都从头到自己扫一遍，找到最大的那个能接上的j（w[i]>w[j]并且w[j]为此区间内最大满足条件的值），更新dp[i]为dp[j]+1
            if (w[j] < w[i]) dp[i] = max(dp[i], dp[j] + 1);
    }

    for (int i = 1; i <= n; i++)
        ans = max(ans, dp[i]);//扫描全区间，找最大值

    printf("%d\n", ans);//输出
}
