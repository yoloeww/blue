#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//1.DP数组的定义：表示i之前包括i的以nums[i]结尾的最长递增子序列的长度
//2.状态转移方程：位置i的最长升序子序列等于j从0——i - 1各个位置的最长升序子序列 + 1
//3.顺序，从前往后
//4.初始化
//5.dp数组
int n;
int lengthOfLIS(vector<int>&nums) {
	vector<int> dp(n + 1, 1);
	int res = 0;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (nums[i] > nums[j]) dp[i] = max(dp[i], dp[j] + 1);
		}
		if (dp[i] > res) res = dp[i];
	}
	return res;
}
int main() {
	cin >> n;
	vector<int>nums;
	nums.resize(n + 1);
	for (int i = 0; i < n; i++)
		cin >> nums[i];
	cout << lengthOfLIS(nums) << endl;
	return 0;
}
