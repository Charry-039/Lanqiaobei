//
// Created by Charry on 2022/5/10.
//

#include "iostream"

using namespace std;
const int N = 100010;
int a[N];
int max_ans[N];
int min_ans[N];
int n, k, idx1 = 1, idx2 = 1;

int main() {
    scanf("%d %d\n", &n, &k);
    int t;
    int maxn = -1000000, minn = 0x3f3f3f3f;
    for (int i = 1; i <= k; i++) {
        scanf("%d", &t);
        a[i] = t;
        maxn = max(maxn, a[i]);
        minn = min(minn, a[i]);
    }
    max_ans[idx1++] = maxn;
    min_ans[idx2++] = minn;
    n -= k;
    while (n--) {
        scanf("%d", &t);
        maxn = -1000000, minn = 0x3f3f3f3f;
        for (int i = 1; i <= k - 1; i++)
            a[i] = a[i + 1];
        a[k] = t;
        for (int i = 1; i <= k; i++) {
            maxn = max(maxn, a[i]);
            minn = min(minn, a[i]);
        }
        max_ans[idx1++] = maxn;
        min_ans[idx2++] = minn;
    }

    for (int i = 1; i < idx2; i++)
        printf("%d ", min_ans[i]);

    printf("\n");

    for (int i = 1; i < idx1; i++)
        printf("%d ", max_ans[i]);
    return 0;
}