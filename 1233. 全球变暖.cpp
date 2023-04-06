#include<iostream>
using namespace std;
const int N = 1010;
int g[N][N];
int n;
char g[N][N]; // g表示地图
bool st[N][N]; // 是否有一整块陆地
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
void bfs(int x,int y,int &total,int &bound) {
    queue<pair<int, int>> q;
    q.push(make_pair(sx, sy));  // 当前坐标入队
    st[sx][sy] = true; // 当前是陆地
    while (q.size()) {
        auto t = q.front();
        q.pop();
        total ++;
        bool is_bound = false;
          for (int i = 0; i < 4; i++) {
            int x = t.first + dx[i]; // 四个方向
            int y = t.second + dy[i];
            if (x < 0 || x >= n || y < 0 || y >= n) continue;
            if (st[x][y]) continue; 
            if (g[x][y] == '.') { // 连接海
               is_bound = true;
                continue;
            }
            q.push(make_pair(x,y));
            st[x][y] = true;
        }
         if (is_bound) bound ++ ; 
    }
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j ++) {
            cin >> g[i][j];
        }
    }
    int cnt = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!st[i][j] && g[i][j] == '#') { // 多少个连通块 
                int total = 0,bound = 0;
                bfs(i,j,total,bound);
                if (bound == total)
                    cnt ++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
