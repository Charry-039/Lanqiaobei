//
// Created by Charry on 2022/5/2.
//

#include "iostream"

using namespace std;
const int N = 1000010;
struct node {
    int left;
    int right;
};
node tree[N];
int n, deep;

void dfs(int step, node root) {
    deep = max(deep, step);
    if (root.left) dfs(step + 1, tree[root.left]);
    if (root.right) dfs(step + 1, tree[root.right]);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &tree[i].left, &tree[i].right);
    if (tree[1].left)dfs(2, tree[tree[1].left]);
    if (tree[1].right)dfs(2, tree[tree[1].right]);
    printf("%d", deep);
    return 0;
}
