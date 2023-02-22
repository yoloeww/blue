#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

#define N 10010
bool check(int year, int month, int day) {
    int months[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (day == 0 || month >= 13 || month == 0)
    return false;
    if (month != 2) {
        if(months[month] < day)
        return false;
    }
    else {
        int leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
        if(day > leap + 28) return false;
        }
        return true;
}
int main() {
    int a,b,c;
    scanf("%d/%d/%d",&a,&b,&c);
    for (int i = 19600101;i <= 20591231; i++) {
        int year = i / 10000;
        int month = i % 10000 / 100;
        int day = i % 100;
        if (check(year, month, day)) {
            if (year % 100 == a && month == b && day == c ||
                month == a && day == b && year % 100 == c ||
                day == a && month == b && year % 100 == c)
                printf("%d-%02d-%02d\n",year,month,day);
        }
    }
    return 0;
}
