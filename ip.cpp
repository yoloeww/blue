#include<iostream>
#include<string>
using namespace std;
int main()
{
   string s;
   int i = 0, t = 0, count = 0;
   bool flag = true;
   while (cin >> s) {
       i = 0;
       count = 0;
       t = 0;
       flag = true;
       while (i < s.size()) {
           if (s[i] == '.') {
               if(t < 0 || t > 255)
               cout << 'N' << endl;
               flag = false;
               break;
           }
           t = 0;
           i++;
           cout++;
       }
       if (s.at(i) < '0' || s.at(i) > '9') {
            cout << 'N' << endl;
                flag = false;
                break;

       }
   }
}
