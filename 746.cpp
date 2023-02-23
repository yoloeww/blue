#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
//1.dp数组含义:到达第i节台阶需要的最少花费为dp[i];
//2.递推公式:dp[i] = min(dp[i - 1] + cost[i - 1] , dp[i - 2] + cost[i - 2];
//3.初始化:dp[0] = 0,dp[1] = 0;
//4.遍历顺序:从前往后
//5.举例推导dp数组:
using namespace std;
int n;
int minCostClimbingStairs(vector<int>& cost) {
	vector<int> dp;
	dp.resize(n + 1);
	dp[0] = 0;
	dp[1] = 0;
	for (int i = 2; i <= n; i++) {
		dp[i] = min(dp[i - 2] + cost[i - 2] ,dp[i - 1] + cost[i - 1]);
	}
	for (int i = 0; i <= n; i++)
		cout << dp[i] << " ";
	return dp[n];
}
int main() {
	vector<int> cost;
	cin >> n;
	cost.resize(n + 1);
	for (int i = 0; i < n; i++)
		cin >> cost[i];
	cout << minCostClimbingStairs(cost);
	return 0;
}
