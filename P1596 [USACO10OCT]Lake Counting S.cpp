#include<iostream>
using namespace std;
int n,m;
const int N = 110;
char gap[N][N];
bool st[N][N];
int dx[] = {1,1,1,0,0,-1,-1,-1};
int dy[] = {-1,0,1,1,-1,1,0,-1};
int res = 0;
void dfs(int x, int y) {
    for (int i = 0; i < 8; i++) {
        int a = x + dx[i];
        int b = y + dy[i];
        if (a < 0 || a >= n || b < 0 || b >= m) continue;
        if (gap[a][b] == '.') continue;
        if (st[a][b]) continue;
        st[a][b] = true;
        dfs(a,b);
    }
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i ++) {
        cin >> gap[i];
    }
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            if(gap[i][j] == 'W' && !st[i][j]) {
                dfs(i,j);
                res ++;
            }
        }
    }
    cout << res << endl;
    return 0;
}
