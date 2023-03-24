#include<iostream>
#include<cmath>
using namespace std;
int r;
const int N = 1010;
int a[N][N];
int dfs(int x,int y) {
	if (x > r || y > r)
		return 0;
	else 
		return max(dfs(x + 1, y), dfs(x + 1, y + 1)) + a[x][y];
}
int main() {
	cin >> r;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < r; j++) {
			cin >> a[i][j];
		}
	}
	dfs(1,1);
	return 0;
}
