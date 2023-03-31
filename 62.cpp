#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
//1.dp数组含义:到达第i行第j列有dp[i][j]条路线;
//2.递推公式:dp[i] = min(dp[i - 1] + cost[i - 1] , dp[i - 2] + cost[i - 2];
//3.初始化:dp[0] = 0,dp[1] = 0;
//4.遍历顺序:从前往后
//5.举例推导dp数组:
using namespace std;

int uniquePaths(int m, int n) {
	vector<vector<int>> dp(m + 1, vector<int> (n + 1));
	int i = 0, j = 0;
	for (int i = 0; i < m; i++)
		dp[i][0] = 1;
	for (int j = 0; j < n; j++)
		dp[0][j] = 1;
	for (i = 1; i < m; i++ )
		for (j = 1; j < n; j++) {
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];

		}
	return dp[m - 1][n - 1];
}
int main() {
	int m, n;
	cin >> m >> n;
	cout << uniquePaths(m, n);
	return 0;
}
