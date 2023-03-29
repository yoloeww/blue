#include<iostream>
using namespace std;
const int N = 1010;
int a[N];
int dp[N]; // 以i结尾的最长递增子序列长度
int n;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int mx = 1;
    for (int i = 0; i < n; i++) { // 右边界
        dp[i] = 1;
        for (int j = 0; j < i; j++) { // 谁比你小
            if (a[i] > a[j]) dp[i] = max(dp[i],dp[j] + 1);
        }
        mx = max(mx, dp[i]);
    }
    cout << mx << endl;
    return 0;
}
