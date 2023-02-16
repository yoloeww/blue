#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<vector>

using namespace std;
const int N=1e5+10;
int h[N],n;
bool check(int mid)//判定能量是否够用 
{
    for(int i = 1; i <= n; i++)
    {
        mid = 2 * mid - h[i];
        if(mid < 0) return false;
        else if(mid >= 1e5) return true;
    }
    return true;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    cin >> h[i];
    int i = 0,j = 1e5;//二分边界 
    while(i < j)
    {
        int mid = i + j >> 1;
        if(check(mid)) j = mid;
        else i = mid + 1;
    }
    cout << j;
    return 0;
}
