#include <iostream>
#include <algorithm>

using namespace std;

const int N = 55;
const int M = 15;
const int MOD = 1e9 + 7;

int n, m, c;
int a[N][N];
// f[i][j][cnt][k] 表示：在 (i, j) 这个点，拿了 cnt 个物品，这些物品中价值最大的是 k
int f[N][N][M][M];

int main() {
  scanf("%d%d%d", &n, &m, &c);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%d", &a[i][j]);
      a[i][j]++;
    }
  }
  // 两个边界初始化
  // 在起点 (1, 1) 处
  // 如果拿也只能拿 a[i][j] 这个物品，只有一种方案
  // 如果不拿，那就是 0 个物品，也是一个方案数
  // 由于物品价值已经增加了一个偏移量，现在价值的范围是 [1, 13]
  // 所以价值为 0 并不代表物品的价值，而是一个边界点
  f[1][1][0][0] = 1;
  f[1][1][1][a[1][1]] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      for (int cnt = 0; cnt <= c; cnt++) {
        for (int k = 0; k < M; k++) {
          // 不拿物品
          f[i][j][cnt][k] = (f[i][j][cnt][k] + f[i - 1][j][cnt][k]) % MOD;
          f[i][j][cnt][k] = (f[i][j][cnt][k] + f[i][j - 1][cnt][k]) % MOD;
          // 可以拿
          if (cnt > 0 && k == a[i][j]) {
            for (int s = 0; s < a[i][j]; s++) {
              f[i][j][cnt][k] = (f[i][j][cnt][k] + f[i - 1][j][cnt - 1][s]) % MOD;
              f[i][j][cnt][k] = (f[i][j][cnt][k] + f[i][j - 1][cnt - 1][s]) % MOD;
            }
          }
        }
      }
    }
  }
  // 最后把在终点 (n, m) 处拿 c 个物品的方案数累加
  int res = 0;
  for (int i = 1; i < M; i++) {
    res = (res + f[n][m][c][i]) % MOD;
  }
  printf("%d\n", res);
  return 0;
}

