//
// Created by Charry on 2022/5/21.
//

#include "iostream"

using namespace std;
const int N = 100010;
int a[N], tree[N];
int n, m;

void add(int l, int v) {
    for (; l <= n; l += l & -l)
        tree[l] += v;
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
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    char c;
    int l, r, d;
    while (m--) {
        cin >> c >> l;
        if (c == 'Q')
            cout << a[l] + query(l) << endl;
        else {
            cin >> r >> d;
            add(l, d);
            add(r + 1, -d);
        }
    }
    return 0;
}