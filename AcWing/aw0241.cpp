//
// Created by Charry on 2022/5/20.
//

#include "iostream"
#include "cstring"

using namespace std;
typedef long long ll;
const int N = 200010;
int a[N], q1[N], q2[N], tree[N]; //q1、q2分别代表V和∧的图腾左右点计算数
int n;
ll res1, res2;//存储两类图腾的数量

void add(int l, int x) {
    for (; l <= n; l += l & -l)
        tree[l] += x;
}

int query(int r) {
    int res = 0;
    for (; r >= 1; r -= r & -r)
        res += tree[r];
    return res;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) {
        //顺序查找&顺序更新tree数组，找左边大于/小于x点的数量
        int x = a[i];
        q1[i] = query(n) - query(x);
        q2[i] = query(x - 1);
        add(x, 1);//更新树状数组
    }
    memset(tree, 0, sizeof tree);//清空顺序查找中更新过的tree数值，以便逆序查找再用
    for (int i = n; i >= 1; i--) {
        //逆序查找&更新，找出右边大于/小于x点的数量
        int x = a[i];
        res1 += q1[i] * 1LL * (query(n) - query(x));
        res2 += q2[i] * 1LL * query(x - 1);
        add(x, 1);
    }
    printf("%lld %lld\n", res1, res2);
    return 0;
}
