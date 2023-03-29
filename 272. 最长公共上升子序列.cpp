#include<iostream>
#include<bits/stdc++.h>

using namespace std;

const int N = 3010;
int a[N];
int b[N];

int n;
int dfs(int i,int j) {
    
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i ++) {
        cin >> b[i];
    }
    dfs(n - 1,n - 1);
    return 0;
}
