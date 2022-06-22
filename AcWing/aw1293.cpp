//
// Created by Charry on 2022/5/3.
//

#include "iostream"

using namespace std;
const int N = 100010;
int prime[N];
bool st[N << 1];

void ola() {
    for (int i = 2; i < N; i++) {
        if (!st[i])prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0]; j++) {
            if (i * prime[j] > N)break;
            st[i * prime[j]] = true;
            if (i % prime[j] == 0)break;
        }
    }
    st[1] = true;
}

int main() {
    ola();
    int n;
    scanf("%d", &n);
    puts(n <= 2 ? "1" : "2");
    for (int i = 2; i <= n + 1; i++)
        if (!st[i])printf("%d ", 1);
        else printf("%d ", 2);
    return 0;
}