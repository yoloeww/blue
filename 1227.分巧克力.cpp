#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int n, k;  // 有n块巧克力，k个小朋友
int wid[N], len[N];  // 分别保存巧克力的长和宽

// 计算当正方形的边长为u时，总共能分得多少块巧克力
int get_sum(int u) {
  int sum = 0;
  for (int i = 0; i < n; i++) {
    // 要的就是整除
    sum += ((wid[i] / u) * (len[i] / u));
  }
  return sum;
}

int main() {
 cin >> n;
 cin >> k;
  for (int i = 0; i < n; i++) {
   cin >> wid[i];
   cin >> len[i];
  }
  // 二分模板
  // 性质是“当边长取mid时，能够分得k块巧克力”
  // 显然在一个数轴上，目标值的左侧（比目标值小的数）都是满足这个性质的，右边则不满足
  // 所以我们要找的值是满足这个性质的最右端
  // 如果当前取的mid满足这个性质，那么l有可能就是我们要找的目标值，所以用l = mid来更新
  // 综上所述，用以下模板
  int l = 0, r = N;
  while (l < r) {
    int mid = (l + r + 1) >> 1;
    if (get_sum(mid) >= k) {
      l = mid;
    } else {
      r = mid - 1;
    }
  }
  printf("%d\n", l);
  return 0;
}
