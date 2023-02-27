#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<queue>

#define x first
#define y second

using namespace std;

const int N = 210;

typedef pair<int, int> PII;

int n, m;
char g[N][N];
int dist[N][N];  // 把判重和距离数组合为一个

int bfs(PII start, PII end)  // 注意 start end都是PII类型的 别写错了
{
    queue<PII> q;

    memset(dist, -1, sizeof dist);  // 把距离数组都初始化成-1

    dist[start.x][start.y] = 0;  // 起点开始，距离为0

    q.push(start);  // 起点 入队

    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

    while(q.size())
    {
        PII t = q.front();

        // 弹出队头
        q.pop();

        for (int i = 0; i < 4; i ++ )
        {
            int a = t.x + dx[i], b = t.y + dy[i]; 

            if (a < 0 || a >= n || b < 0 || b >= m) continue;  // 出界，跳出本次循环
            if (dist[a][b] != -1) continue;    // 走过了，跳出本次循环
            if (g[a][b] == '#') continue;    // 撞到障碍物

            dist[a][b] = dist[t.x][t.y] + 1;

            if (end == make_pair(a, b)) return dist[a][b];  // 走到终点了，返回距离

            q.push({a, b});
        }

    }

    return -1;
}

int main()
{
    int T;
    cin >> T;

    while(T --)
    {

        scanf("%d%d", &n, &m);

        for (int i = 0; i < n; i ++ ) scanf("%s", g[i]);

        PII start, end;
        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < m; j ++ )
                if (g[i][j] == 'S') start = {i, j};
                else if (g[i][j] == 'E') end = {i, j};

        int distance = bfs(start, end);

        if (distance == -1) printf("oop!\n");
        else printf("%d\n", distance);

    }

    return 0;
}
