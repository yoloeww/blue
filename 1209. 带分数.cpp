#include<iostream>
using namespace std;
bool used[10];
const int N = 10;
int n;
int num[N];
int cnt = 0;
int calc(int l,int r) {
    int res = 0;
    for (int i = l; i <= r; i++) {
        res = res * 10 + num[i];
    }
    return res;
}
void dfs(int u) {
    if (u >= 9) {
        for (int i = 0; i < 7; i++) {
            for (int j = i + 1; j < 8; j++) {
                int a = calc(0,i);
                int b = calc(i + 1,j);
                int c = calc(j + 1,8);
                if (a * c + b == c * n) {
                    cnt ++;
                }
            }
        }
        return ;
    }
    for (int i = 1; i <= 9; i++) {
        if (!used[i]) {
            used[i] = true;
            num[u] = i;
            dfs(u + 1);
            used[i] = false;
        }
    }
}
int main() {
    cin >> n;
    dfs(0);
    cout << cnt << endl;
    return 0;
}
