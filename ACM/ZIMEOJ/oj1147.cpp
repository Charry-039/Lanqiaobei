#include <cstdio>

int main() {
  int i, j, n, num = 1;
  int a[100][100] = {0}; //初始化为0，当然也可以用memset
  scanf("%d", &n);
  int cnt = n / 2; //注意这个cnt

  for (i = 0; i <= cnt; i++) //请思考一下为什么这里带等号
  {
    for (j = i; j < n - i; j++) //从上面第1层开始横向移动并输入数字执行n-i次
      a[i][j] = num++;
    for (j = i + 1; j < n - i; j++) //接着上面的
      a[j][n - i - 1] = num++;
    for (j = n - 2 - i; j >= i; j--) //想想走到这里为什么变成了n-2
      a[n - i - 1][j] = num++;
    for (j = n - 2 - i; j >= 1 + i; j--)
      a[j][i] = num++;
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++)
      printf("%5d", a[i][j]);
    puts("");
  }
}
