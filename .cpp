#include <iostream>
#include <cstring>
using namespace std;
int main()
{
   string str;
   int N = 0;
   cin >> N;
   getchar();
   while(N-- && getline(cin,str)) {
       cout << str << endl << endl;
   }
   while(cin >> str){
        cout << str << endl << endl; // 输出不带空格的
    }
    return 0;
}
