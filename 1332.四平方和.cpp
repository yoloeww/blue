#include<iostream>
using namespace std;
#include<unordered_map>
typedef pair <int ,int > PII;
unordered_map <int, PII> s;
int main()
{
    int n;
    cin >> n;
    int a,b,c,d;
    for (int c = 0 ; c <= n; c ++) 
        for(int d = c; d * d + c * c <= n; d++) {
            int t = c * c + d * d;
            if(s.count(t) == 0)
            s[t] ={c,d};
       }
       for (int a = 0 ; a <= n; a ++) 
        for(int b = a; a * a + b * b <= n; b ++) {
              int t = n - a * a + b * b;
              if(s.count(t)) {
              cout << a << " "<< b <<" "<< s[t].first<<" "<< s[t].second;
              return 0;
              }
        }
    return 0;
}
