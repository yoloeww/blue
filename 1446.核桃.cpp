#include<iostream>
using namespace std;
int main()
{
   long long a,b,c;
   cin >> a;
   cin >> b;
   cin >> c;
   for(long long i = 1; i < 30 * 30 * 30;i++){
       if(i  % a == 0 && i % b == 0 && i % c == 0) {
       cout << i << endl;
       break;
       }
   }
   return 0;
}
