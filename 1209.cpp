#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 10;

int target; // 目标数
int num[N]; // 全排列结果
bool used[N]; // 是否使用过
int cnt; // 方案数计数

int cal(int l, int r) {
    int res = 0;
    for (int i = l; i <= r; i++) {
        res = res * 10 + num[i];
    }
    return res;
}

void dfs(int u) {
    if (u == 9) {
        for (int i = 0; i < 7; i++) {
            for (int j = i + 1; j < 8; j++) {
               int a = cal(0, i);
               int b = cal(i + 1, j);
               int c = cal(j + 1, 8);
               if (a * c + b == c * target) {
               cnt++;
            }
        }
    }
    return ;
}
    for (int i = 1; i <= 9; i++) {
        if( !used[i]) {
            used[i] = true;
            num[u] = i;
            dfs(u + 1);
            num[u] = 0;
            used[i] = false;
        }
    }
}
int main() {
    scanf("%d", &target);
    dfs(0);
    printf("%d\n",cnt);
    return 0;
}
