//
// Created by Charry on 2022/5/19.
//

#include "iostream"

using namespace std;
const int N = 20010;
int dp[N];
int v, n, t;

int main() {
    scanf("%d%d", &v, &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &t);
        for (int j = v; j >= t; j--)
            dp[j] = max(dp[j], dp[j - t] + t);
    }
    printf("%d\n", v - dp[v]);
    return 0;
}
