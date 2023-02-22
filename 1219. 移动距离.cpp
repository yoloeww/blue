#include <bits/stdc++.h>

using namespace std;

int main(){
    int w, m, n;
    cin >> w >> m >> n;
    m --, n --;//序号减1，便于利用公式求行号和列号

    int x1 = m / w, x2 = n / w;//行号
    int y1 = m % w, y2 = n % w;//求列号
    if(x1 & 1) y1 = w - 1 - y1;//特判，是否为奇数行
    if(x2 & 1) y2 = w - 1 - y2;

    //曼哈顿顿距离
    cout << abs(x1 - x2) +abs(y1 - y2) << endl;
    return 0;
}

