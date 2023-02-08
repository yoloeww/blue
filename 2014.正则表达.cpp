#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,x,y;
int main(){
        cin >> n >> x >> y;
        cout<< y - x + 1-( (ll)sqrt(y)-(ll)sqrt(x-1));
        return 0;
}
