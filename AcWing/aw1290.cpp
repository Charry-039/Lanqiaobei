//
// Created by Charry on 2022/5/2.
//

#include "iostream"
#include "cmath"
using namespace std;
typedef long long ll;
const int mod = 100003;

long long C(long long n, long long m) {
    long long ans = 1;
    long long gap = n - m;
    for (long long i = 1; i <= m; i++)
        ans = (ans * (gap + i)) / i;    //注意：一定要先乘再除！！！
    return ans;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    printf("%lld", C(n, m));
    return 0;
}