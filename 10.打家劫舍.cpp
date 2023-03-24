#include<iostream>
#include<bits/stdc++.h>
#include<cmath>
using namespace std;
int n;
const int N = 10010;
int mem[N];
int home[N];
int dfs(int x) {

	if (mem[x]) return mem[x]; // 从第i个店铺开始可以洗劫到的最大价值

	int sum = 0;
	if (x > n) sum = 0;
	else sum = max(dfs(x + 1), dfs(x + 2) + home[x]);

	mem[x] = sum;
	return sum;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> home[i];
		}
		for (int i = 1; i <= n; i++) {// 1 2 3 4 5 传 5  从 1 - 5的最大
			f[i] = max(f[i - 1], f[i - 2] + home[i]);
			f[i + 2] = max(f[i + 1], f[i] + home[i])
		}
		for (int i = n; i >= 1; i--) { // 5 4 3 2 1 传 1 从1开始
			f[i] = max(f[i + 1], f[i + 2] + home[i]);
		}
		int newf = 0, tmp1 = 0, tmp2 = 0;
		for (int i = 1; i <= n; i++) {
			newf = max(tmp1, tmp2 + home[i]);
			tmp2 = tmp1;
			tmp1 = newf;
		}
		memset(mem, 0, sizeof mem);
		int res = dfs(1);
		cout << res << endl;
	}
	return 0;
}
