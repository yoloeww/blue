#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
#define N 1010
int main() {
    int n, m, q;
    cin >> n;
    cin >> m;
    cin >> q;
    int a[N][N] = {0};
    int s[N][N] = {0};
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
         cin >> a[i][j];
           s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
        }
    }
    int x1,x2,y1,y2;
    while (q--) {
        cin >> x1 ;
        cin >> y1;
        cin >> x2;
        cin >> y2;
        cout <<  s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1]<< endl;
    }
    return 0;
}
