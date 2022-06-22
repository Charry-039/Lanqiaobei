//
// Created by Charry on 2022/5/3.
//

#include "iostream"
#include "cstring"

using namespace std;
typedef long long ll;

const int N = 1e6 + 10;

int pri[N];
bool st[N];
int cnt;

void ola(int n) {
    memset(pri, 0, sizeof pri);
    memset(st, false, sizeof st);//因为题目需要循环读入，所以每一次都需要清空数组
    cnt = 0;
    st[1] = true;
    for (int i = 2; i <= n; i++) {
        if (!st[i]) pri[++cnt] = i;
        for (int j = 1; i * pri[j] <= n; j++) {
            st[i * pri[j]] = true;
            if (i % pri[j] == 0)break;
        }
    }
}

int main() {
    int l, u;
    while (scanf("%d %d\n",&l,&u)==2) {
        ola(50010);//欧拉筛，筛掉前一部分的质数
        memset(st, false, sizeof st);//下面代码需要复用st数组，所以清空一次
        for (int i = 1; i <= cnt; i++) {
            ll p = pri[i];
            for (ll j = max(p << 1, (p + l - 1) / p * p); j <= u; j += p)
                st[j - l] = true;  //l作为偏移量，后面会把它加回来
        }
        cnt = 0;    //因为最后要的质数范围为[l,u],所以重置下标，pri从更新过后的st开始判，只存[l,u]内的质数
        for (int i = 0; i <= u - l; i++)
            if (!st[i] && i + l >= 2)
                pri[++cnt] = i + l; //加回偏移量
        if (cnt < 2) {
            //[l,u]内的质数数量不到一对
            puts("There are no adjacent primes.");
        } else {
            //在pri数组中查找最远/近的质数对
            int minp = 1, maxp = 1;
            for (int i = 1; i <= cnt - 1; i++) {
                int d = pri[i + 1] - pri[i];
                if (d < pri[minp + 1] - pri[minp]) minp = i;
                if (d > pri[maxp + 1] - pri[maxp]) maxp = i;
            }
            printf("%d,%d are closest, %d,%d are most distant.\n", pri[minp], pri[minp + 1], pri[maxp], pri[maxp + 1]);
        }
    }
    return 0;
}