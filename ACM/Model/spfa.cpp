#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int N = 20010, M = 200010, INF = 0x3f3f3f3f;
int h[N], e[M], ne[M], w[M], dist[N];
bool st[N];
int idx;

void add(int a, int b, int c) {
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}

void spfa() {
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    st[1] = true;
    while (q.size()) {
        int t = q.front();
        q.pop();
        st[t] = false;
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dist[j] > dist[t] + w[i]) {
                dist[j] = dist[t] + w[i];
                if (!st[j]) {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
}

int main() {
    int n, m, a, b, c;
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);
    memset(dist, INF, sizeof dist);
    while (m--) {
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }
    spfa();
    for (int i = 2; i <= n; i++)
        printf("%d\n", dist[i]);
}