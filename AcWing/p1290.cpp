//
// Created by Charry on 2022/6/6.
//
#include "iostream"

using namespace std;

typedef long long ll;

const int mod = 100003;

int quick_pow(ll base, ll pow) {
    ll res = 1;
    while (pow) {
        if (pow & 1) res = (res * base) % mod;
        pow >>= 1;
        base = (base * base) % mod;
    }
    return res;
}

int main() {
    ll n, m;
    scanf("%lld%lld", &m, &n);
    printf("%lld\n", (quick_pow(m, n) - m * quick_pow(m - 1, n - 1) % mod + mod) % mod);
    //例如模数是 10，那么 11 - 8 取模以后就是 1 - 8 是负数
    return 0;
}
