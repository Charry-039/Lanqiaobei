//
// Created by Charry on 2022/5/23.
//

#include "iostream"

using namespace std;
const int N = 100010;
int a[N];
int n, m;

void insert(int l, int r, int d) {
    a[l] += d;
    a[r + 1] -= d;
}

int main() {
    int t, l, r, d;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &t);
        insert(i, i, t);
    }
    while (m--) {
        scanf("%d%d%d", &l, &r, &d);
        insert(l, r, d);
    }
    for (int i = 1; i <= n; i++) {
        a[i] += a[i - 1];
        printf("%d ", a[i]);
    }

    return 0;
}