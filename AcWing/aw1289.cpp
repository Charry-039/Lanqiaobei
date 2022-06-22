//
// Created by Charry on 2022/5/2.
//

#include "iostream"

using namespace std;
const int mod = 200907;
typedef long long ll;

ll quick_pow(ll base, ll pow) {
    ll res = 1 % mod;
    while (pow) {
        if (pow & 1) res = (res * base) % mod;
        pow >>= 1;
        base = (base * base) % mod;
    }
    return res;
}

ll quick_add(ll a, ll b) {
    ll res = 0;
    while (b) {
        if (b & 1) res = (res + a) % mod;
        b >>= 1;
        a = (a + a) % mod;
    }
    return res;
}

int main() {
    int t, a, b, c, k;
    scanf("%lld", &t);
    while (t--) {
        scanf("%lld%lld%lld%lld", &a, &b, &c, &k);
        if (a + c == (b << 1)) printf("%lld\n", (a + quick_add(b - a, k - 1)) % mod);
        else printf("%lld\n", a * quick_pow(b / a, k - 1) % mod);
    }
    return 0;
}
