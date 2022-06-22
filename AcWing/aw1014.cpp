#include "iostream"

using namespace std;
const int N = 1010;
int w[N], dp1[N], dp2[N];
int n, ans;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &w[i]);

    for (int i = 1; i <= n; i++) {
        dp1[i] = dp2[i] = 1;
        for (int j = 1; j <= i - 1; j++) {
            if (w[i] > w[j]) dp1[i] = max(dp1[i], dp1[j] + 1);
            else if (w[i] < w[j]) dp2[i] = max(dp2[i], max(dp1[j] + 1, dp2[j] + 1));
        }
    }

    for (int i = 1; i <= n; i++)
        ans = max(ans, max(dp1[i], dp2[i]));

    printf("%d", ans);
    return 0;
}