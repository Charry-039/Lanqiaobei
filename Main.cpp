#include "iostream"

using namespace std;
const int N = 1000010;
int prime[N];
bool st[N << 1];

void ola() {
    st[1] = true;
    for (int i = 1; i < N; i++) {
        if (!st[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0]; j++) {
            if (i * prime[j] > N)break;
            st[i * prime[j]] = true;
            if (!i % prime[j])break;
        }
    }
}

int main() {
    ola();
    int t, n;
    scanf("%d\n", &t);
    while (t--) {
        scanf("%d\n", &n);
        int a[n + 1];
        bool f = true;
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        bool f1 = a[1] & 1;//奇数为true
        if (st[a[1]] && a[1] & 1 && (a[1] - 5) & 1)
            f = false;
        for (int i = 2; i <= n; i++) {
            if (!f)break;
            if (f1) {
                //2
                if (a[i] & 1)f = false; //无法变为2
                else a[i] = 2;
            } else {
                //5
                if (abs(a[i] - 5) & 1)f = false;
                else a[i] = 5;
            }
            f1 = (a[i] & 1);
        }
        puts(f ? "YES" : "NO");
    }
    return 0;
}