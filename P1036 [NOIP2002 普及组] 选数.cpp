#include<iostream>
using namespace std;
const int N = 30;
int n,k;
int cnt = 0;
int a[N];
int state[N];
bool check(int x) {
    for (int i = 2; i < x / i; i++) {
        if (x % i == 0)
            return false;
    }
    return true;
}
void dfs(int x,int start,int sum) {
    if (x > k) {
        if (check(sum))
            cnt ++;
        return ;
    }
    for (int i = start; i <= n ;i++) {
        state[x] = a[i];
        dfs(x + 1,i + 1,sum + state[x]);
        state[x] = 0;
    }
}
int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dfs(1,1,0);
    cout << cnt << endl;
    return 0;
}
