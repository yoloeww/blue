
0


#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
    int n, m;
    cin >> n;
    int x;
    cin >> m;
    vector<int> s(n + 10);
    for (int i = 1; i <= n; i++) {
        cin >> x;
        s[i] = s[i - 1] + x;
    }
    int l,r;
    while (m--) {
        cin >> l;
        cin >> r;
        cout << s[r] - s[l - 1] << endl;
    }
    return 0;
}

