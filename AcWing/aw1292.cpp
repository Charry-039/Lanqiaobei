//
// Created by Charry on 2022/4/27.
//

#include "iostream"

using namespace std;
const int N = 1000010, M = N << 1;
int prime[N];
bool st[M];

void ola() {
    st[1] = true;
    for (int i = 2; i < N; i++) {
        if (!st[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0]; j++) {
            if (i * prime[j] >= N) break;
            st[i * prime[j]] = true;
            if (i % prime[j] == 0)break;
        }
    }
}

int main() {
    int x, l = 0, r = 0;
    bool f;
    ola();
    while (scanf("%d", &x) == 1) {
        if (x == 0)break;
        f = false;
        for (int i = 1; i < N; i++) {
            l = prime[i];
            if (!st[x - l]) {
                r = x - l;
                f = true;
                break;
            }
        }
        if (f)printf("%d = %d + %d\n", x, l, r);
        else printf("%s\n", "Goldbach's conjecture is wrong.");
    }
    return 0;
}