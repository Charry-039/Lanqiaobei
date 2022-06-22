//
// Created by Charry on 2022/6/21.
//

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;

int a[N << 1];

int main() {
    int n, idx = 0, res = 1, t = 0;
    scanf("%d", &n);
    while (n--) {
        int l, r;
        scanf("%d%d", &l, &r);
        a[++idx] = l << 1;
        a[++idx] = (r << 1) + 1;
    }
    sort(a + 1, a + idx + 1);
    for (int i = 1; i <= idx; i++) {
        if (a[i] % 2 == 0) t++;
        else t--;
        res = max(res, t);
    }
    printf("%d\n", res);
    return 0;
}