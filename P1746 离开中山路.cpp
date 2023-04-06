#include<iostream>
#include<queue>
#include <cstring>
using namespace std;
const int N = 1010;
char gap[N][N];
int dist[N][N];
int x1, y1, x2, y2;
typedef pair<int, int> PII;
int n;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int bfs(int x1, int y1) {
	memset(dist,-1,sizeof dist);
	queue<PII> q;
	q.push({x1,y1});
	dist[x1][y1] = 0;
	while (q.size()) {
		auto t = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int a = t.first + dx[i];
			int b = t.second + dy[i];
			if (a < 1 || a > n || b < 1 || b > n) continue;
			if (dist[a][b] >= 0) continue;
			if (gap[a][b] == '1') continue;
			q.push({ a,b });
			dist[a][b] = dist[t.first][t.second] + 1;
			if (dist[x2][y2] > 0) return dist[x2][y2];
		}
	}
	return -1;
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) 
		cin >> gap[i][j];
	}
	cin >> x1 >> y1 >> x2 >> y2;
	cout << bfs(x1, y1) << endl;
	return 0;
}
