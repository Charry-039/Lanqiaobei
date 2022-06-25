//
// Created by Charry on 2022/6/24.
//

#include "iostream"
#include "queue"

using namespace std;

priority_queue<int, vector<int>, greater<int>> q;

int main() {
    int n, t, res = 0;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &t);
        q.push(t);
    }
    while (q.size() > 1) {
        t = q.top();
        q.pop();
        t += q.top();
        q.pop();
        q.push(t);
        res += t;
    }
    printf("%d\n", res);
    return 0;
}