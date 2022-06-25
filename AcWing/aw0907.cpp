#include "iostream"
#include "algorithm"

using namespace std;

const int N = 1e5 + 10;

struct Range {
    int l, r;

    bool operator<(const Range &w) const {
        return l < w.l;
    }
} range[N];

int n, s, t, res;
bool st;

int main() {
    scanf("%d%d%d", &s, &t, &n);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &range[i].l, &range[i].r);
    sort(range + 1, range + n + 1);
    for (int i = 1; i <= n; i++) {
        int j = i, r = -2e9;
        while (j <= n && range[j].l <= s) {
            r = max(r, range[j].r);
            ++j;
        }
        if (r < s) {
            st= false;
            break;
        }
        ++res;
        if (r >= t){
            st= true;
            break;
        }
        s = r;
        i = j - 1;
    }
    printf("%d\n", st?res:-1);
    return 0;
}