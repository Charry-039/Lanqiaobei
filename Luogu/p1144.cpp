//
// Created by Charry on 2022/5/12.
//

#include "iostream"
#include "cstring"
#include "queue"

using namespace std;
int const N = 1000010;
int h[N], e[N], ne[N], num[N];
bool st[N];
int n, m, idx;

void add(int x, int y) {
  e[idx] = y;
  ne[idx] = h[x];
  h[x] = idx++;
}

void bfs(int end) {
  queue<int> q;
  q.push(e[1]);
  int cnt = 0;
}

int main() {
  memset(h, -1, sizeof h);
  scanf("%d%d\n", &n, &m);
  int u, v;
  while (m--) {
    scanf("%d%d", &u, &v);
    add(u, v);
  }
  for (int i = 1; i <= n; i++) {
    memset(st, false, sizeof st);
    bfs(i);
  }
  return 0;
}