#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>

//这个宏定义其实也就最后输出的时候应用了（如果我没猜错的话），但是y总的习惯就是好习惯！
#define x first
#define y second

using namespace std;

typedef pair<int,int> PII;

const int N=5;

char g[N][N],backup[N][N];


//映射函数
int get(int x,int y)
{
    return x*4+y;//返回第x行第y列上的数是多少
}

void turn_one(int x,int y)
{
    if(g[x][y]=='+') g[x][y]='-';
    else g[x][y]='+';
}

void turn_all(int x,int y)
{
    for(int i=0;i<4;i++)
    {
        turn_one(x,i);
        turn_one(i,y);
    }
    turn_one(x,y);

}

int main()
{
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            cin>>g[i][j];

    vector<PII> res;//这是记录方案所需要的结构

    //枚举所有的方案
    for(int op=0;op<1<<16;op++)
    {
        vector<PII> temp;//temp里面存的是方案
        //先备份一下，为什么？因为这又不是最终方案，我们要把所有方案都试一遍，求最少的
        memcpy(backup,g,sizeof g);

        //枚举16个位置,进行操作
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)
                if(op>>get(i,j)&1) //如果当前位置是1的话--get的作用就是返回二进制数中那一位是第几位，从而判断是否为1
                {
                    temp.push_back({i,j});
                    //按一下开关
                    turn_all(i,j);
                }


        //判断所有灯泡是否全亮
        bool has_closed=false;
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)
                if(g[i][j]=='+') has_closed=true;

        if(has_closed==false)
        {
            //如果方案为空或者他的操作数大于我们刚存好的新的方案，那么就修改它
            if(res.empty()||res.size()>temp.size()) res=temp;
        }
        //还原回来，供下一个方案操作
        memcpy(g,backup,sizeof g);
    }
    //因为没说无解，所以可以猜想一下一定有解
    cout<<res.size()<<endl;
    //这里的迭代函数就是一种简便写法，不要误解
    //另外原题下标从1开始，所以下面加1了
    for(auto op:res) cout<<op.x+1<<" "<<op.y+1<<endl;

    return 0;
}
