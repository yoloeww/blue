#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
bool fun(int n) {
    string cur = to_string(n);
    string temp = cur;
    reverse(temp.begin(), temp.end());
    if(cur != temp)
    return false;
    else
    return true;
}
int main()
{
    int n;
    int t = 0;
    cin >> n;
    for(int i = 10000; i <= 999999; i ++){
     int sum = 0;
     if(fun(i)){
         while(i) {
             sum += i % 10;
             i = i / 10;
         }
         if(sum == n){
         t++;
         cout << sum << endl;
         }
     }
    }
    if(t == 0)
  cout << "-1" << endl;
  return 0;
}
