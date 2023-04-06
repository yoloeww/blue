#include<iostream>
#include<bits/stdc++.h>
using namespace std;
string str;
int k = 0;
int dfs() {
    int res = 0;
    while (k < str.size()) {
        if (str[k] == '(') {
            k ++;
            res += dfs();
            k ++;
        }
        else if (str[k] == '|') {
            k ++;
            res = max(res,dfs());
        }
        else if (str[k] == ')') break;
        else {
            k ++;
            res ++;
        }
    }
    return res;
}
int main() {
    cin >> str;
    cout << dfs() << endl;
    return 0;
}
