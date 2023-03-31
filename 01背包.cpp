#include<iostream>
using namespace std;
const int N = 1010;
int v[N]; // 体积
int w[N]; // 价值
int dp[N][N]; // j体积下前i个物品的最大值
int main()
{
    int n, m;
    cin >> n;
    cin >> m;
    for (int i = 1; i <= n; i++) 
            cin >> v[i] >> w[i];
            
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= m; j++) {
              if (j < v[i]) // 当前背包容量不够，没得选，所以为i - 1个和
                dp[i][j] = dp[i - 1][j];
              else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i]] + w[i]); // 容量够，可以选，因此需要决策选与不选第 i 个物品
    
        }

        cout << dp[n][m] << endl;
    return 0;
}
