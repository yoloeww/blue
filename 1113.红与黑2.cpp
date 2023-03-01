#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
#define N 22
int m,n;
using namespace std;
char map[N][N];
bool use[N][N];
typedef pair<int, int> PII;

int mx[4] = {-1, 0, 1, 0};
int my[4] = {0, 1, 0, -1};

int bfs(int x, int y) {
    queue<PII> q;
    q.push({x, y});
    int cnt = 1;
    while (q.size()) {
        auto t = q.front();
        q.pop();
        int x = t.first;
        int y = t.second;
        for (int i = 0; i < 4; i++) {
                int a = x + mx[i];
                int b = y + my[i];
                if (a < 0 || a >= n || b < 0 || b >= m) continue;
                if (use[a][b]) continue;
                if (map[a][b] != '.') continue;
                cnt ++;
                q.push({a,b});
                use[a][b] = true;
                }
            }
    return cnt;
}
int main() {
    while (cin >> m >> n , m || n) {
       memset(use,0,sizeof use);
       for (int i = 0; i < n;i ++) {
           for (int j = 0; j < m; j ++) {
               cin >> map[i][j];
           }
       }
        int x,y,flag = 0;
        for (int i = 0; i < n; i ++)  {
            for (int j = 0; j < m; j++) 
             if (map[i][j] == '@') {
                   x = i;
                   y = j;
                   flag = 1;
             }
             if(flag) break;
        }
            cout << bfs(x, y) << endl;
    }
    return 0;
}
