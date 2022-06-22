#include "iostream"

using namespace std;

const int N = 1e5 + 10, M = 1e6 + 10;

int a[N], cnt[M], res[M];
int n;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]), ++cnt[a[i]];

    for (int i = 1; i < M; i++) {
        if (!cnt[i])continue;
        for (int j = i; j < M; j += i)
            res[j] += cnt[i];
    }

    for (int i = 1; i <= n; i++)
        printf("%d\n", res[a[i]] - 1);
}