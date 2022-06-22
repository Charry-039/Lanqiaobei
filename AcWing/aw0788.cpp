//
// Created by Charry on 2022/4/5.
//

#include <iostream>

using namespace std;
const int N = 100010;
int a[N];
long long ans;

void meger_sort(int l, int r) {
    if (l >= r)return;
    int mid = (l + r) >> 1;
    meger_sort(l, mid);
    meger_sort(mid + 1, r);
    int i = l, j = mid + 1, k = 1;
    int t[N];
    while (i <= mid & j <= r) {
        if (a[i] <= a[j]) t[k++] = a[i++];
        else {
            ans += mid - i + 1;
            t[k++] = a[j++];
        }
    }
    while (i <= mid) t[k++] = a[i++];
    while (j <= r) t[k++] = a[j++];
    for (i = l, j = 1; i <= r;) a[i++] = t[j++];
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    meger_sort(1, n);
    cout << ans;
    return 0;
}