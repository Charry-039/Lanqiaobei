//
// Created by Charry on 2022/6/20.
//

#include "iostream"
#include "algorithm"

using namespace std;

const int N = 100010;

struct Range {
    int l, r;

    bool operator<(const Range &w) {
        return this->r < w.r;
    }
};

Range range[N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &range[i].l, &range[i].r);
    sort(range + 1, range + n + 1);
    int res = 0, end = -2e9;
    for (int i = 1; i <= n; i++)
        if (end < range[i].l) {
            end = range[i].r;
            ++res;
        }
    printf("%d\n", res);
    return 0;
}