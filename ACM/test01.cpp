#include "iostream"
#include "algorithm"

using namespace std;

int main() {
    int a[] = {-31, 3, -95, -42, -18, 42, -95, -9, -47, 85, -45, -5};
    int n = 11;
    sort(a + 1, a + n);

    for (int i = 1; i <= n; i++)
        printf("%d ", a[i]);

    sort(a, a + n);
    puts("");
    for (int i = 1; i <= n; i++)
        printf("%d ", a[i]);

    return 0;
}