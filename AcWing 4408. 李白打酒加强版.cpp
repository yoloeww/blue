#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long LL;
const int N = 110;
LL n, m, ans, len;
LL res[N];    //用来记录李白路过花和店的序列 
void dfs(int i,LL k,LL a,LL b) {
    if (a > m || b > n)
        return ;
    if (i == len - 1 ) {
        if (k == 1 && a == m - 1 && b == n) {
            ans ++;
        }
        return ;
    }
    if (k <= 0) return;
    
    dfs(i + 1,k - 1,a + 1,b);
    
    dfs(i + 1,k + k, a, b + 1);
    
}
int main() {
    cin >> n >> m;
    len = n + m;
    dfs(0, 2, 0, 0);
    ans = ans % mod;
    cout << ans;
    return 0;
}
