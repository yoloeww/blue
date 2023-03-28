#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int N = 10010;
int dp[N], vb[N], w[N];
int main()
{
    int n, v;
    cin >> n >> v;
    for (int j = 1; j <= n; j++) {
        cin >> vb[j] >>w[j];
    }
    for (int j = 1; j <= v; j++) {
        for (int i = 1; i <=n; i++) {
            if (j - vb[i] < 0)continue;
            else
            dp[j] = max(dp[j - vb[i]] + w[i], dp[j]);
        }
    }
    cout << dp[v];
    return 0;
}
