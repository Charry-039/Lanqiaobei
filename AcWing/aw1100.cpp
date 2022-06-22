//
// Created by Charry on 2022/5/12.
//

#include "iostream"
#include "queue"

using namespace std;
const int N = 100010;
int dir[] = {0, -1, 1};
int step[N];
bool st[N];
int now;
int n, k;

int bfs() {
    queue<int> q;
    q.push(n);
    st[n] = true;
    while (!q.empty()) {
        int front = q.front();
        q.pop();
        for (int i = 1; i <= 3; i++) {
            now = (i == 3) ? front * 2 : front + dir[i];
            if (now >= 0 && now <= 100000 && !st[now]) {
                q.push(now);
                st[now] = true;
                step[now] = step[front] + 1;
            }
            if (now == k)return step[k];
        }
    }
    return -1;
}

int main() {
    scanf("%d%d", &n, &k);
    printf("%d\n", bfs());
    return 0;
}