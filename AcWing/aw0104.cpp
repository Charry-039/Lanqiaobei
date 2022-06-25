//
// Created by Charry on 2022/6/24.
//

#include "iostream"
#include "algorithm"

using namespace std;

const int N = 1e5 + 10;

int a[N];

int main() {
    int n, res = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    int mid = a[(n >> 1) + 1];
    for (int i = 1; i <= n; i++)
        res += abs(a[i] - mid);
    printf("%d\n", res);
    return 0;
}