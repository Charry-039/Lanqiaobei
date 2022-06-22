//
// Created by Charry on 2022/4/22.
//

#include <iostream>

using namespace std;
typedef long long ll;

ll guishuchen(ll a, ll b, ll p) {
    ll res = 0;
    while (b) {
        if (b & 1)res = (res + a) % p;
        b >>= 1;
        a = (a + a) % p;
    }
    return res;
}

int main() {
    ll a, b, p;
    scanf("%lld%lld%lld", &a, &b, &p);
    printf("%lld", guishuchen(a, b, p));
    return 0;
}