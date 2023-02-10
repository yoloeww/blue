#include<cstring>
#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 9;

int state[N];
bool use[N];
int n;
void dfs(int u) {
    if (u > n)
    {
        for (int i = 1; i <= n; i++)
        printf("%d ",state[i]);
        cout << endl;
        return ;
    }
    for(int i = 1; i <= n; i++) {
       if(!use[i]) {
           state[u] = i ;
           use[i] = true;
           dfs(u + 1);
           state[u] = 0;
           use[i] = false;
       }
    }
}
int main() {
    cin >> n;
    dfs(1);
    return 0;
}
