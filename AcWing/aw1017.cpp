#include <cstring>
#include "iostream"

using namespace std;
const int N = 110;
int w[N];
int up[N], down[N];

int main() {
    int n, ans;
    ans = 0;
    memset(w, 0, sizeof w);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &w[i]);

    for (int i = 1; i <= n; i++) {
        down[i] = 1;
        for (int j = 1; j <= i - 1; j++)
            if (w[i] < w[j]) down[i] = max(down[i], down[j] + 1);
    }

    for (int i = n; i >= 1; i--) {
        up[i] = 1;
        for (int j = n; j >= i + 1; j--)
            if (w[i] < w[j]) up[i] = max(up[i], up[j] + 1);
    }

    for (int i = 1; i <= n; i++)
        ans = max(ans, max(down[i], up[i]));

    printf("%d\n", ans);
    return 0;
}