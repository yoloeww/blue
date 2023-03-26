#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
  ll a,b;
  cin>>a>>b;
  ll c=b-a;
  cout<<c-(a%c);
  return 0;
}
