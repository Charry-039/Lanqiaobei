//
// Created by Charry on 2022/6/24.
//

#include "iostream"
#include "algorithm"

typedef long long LL;

using namespace std;

const int N = 1e5 + 10;

int a[N];

int main() {
    int n;
    LL res = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
        res += a[i] * (n - i);
    printf("%lld\n", res);
    return 0;
}