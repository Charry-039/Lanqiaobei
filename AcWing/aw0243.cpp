//
// Created by Charry on 2022/5/21.
//

#include "iostream"

using namespace std;
typedef long long ll;
const int N = 100010;
int a[N], tree[N];
int n, m;

void add(int r, int v) {
    a[r] += v;
    for (; r <= n; r++)
        tree[r] += v;
}

int query(int r) {
    int res = 0;
    for (; r >= 1; r -= r & -r)
        res += tree[r];
    return res;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    int t;
    for (int i = 1; i <= n; i++) {
        cin >> t;
        add(i, t);
    }
    char q;
    int l, r, d;
    while (m--) {
        cin >> q >> l >> r;
        if (q == 'C') {
            //区间加
            cin >> d;
            add(l, d);
            add(r + 1, -d);
        } else//区间查
            cout << query(r)<<" "<<query(l - 1) << endl;
    }
    return 0;
}