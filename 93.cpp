#include<cstring>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


int n,m;
vector<int> state(n);
vector<bool> use (m);
void dfs(int u) {
    if(u == m) {
        for(int i = 0; i < m; i++)
        printf("%d ",state[i]);
        cout << endl;
    }
    for(int i = 1; i <= m; i++) {
         if(!use[i]) {
        state[i] = i;
        use[i] = true;
        dfs(u + 1);
        state[u] = 0;
        use[i] = false;
         }
    }
}
int main() {
    cin >> n;
    cin >> m;
    dfs(1);
    return 0;
}
