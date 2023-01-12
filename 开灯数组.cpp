/*
r:row    行  
c:column 列 
*/
#include<iostream>
#include<cstdio>
using namespace std;
int puzzle[6][8];//存储灯的初始状态，0表示灯是熄灭的，1表示灯是被点亮的 
int press[6][8];//存储最后计算的结果，0表示不按按钮，1表示按按钮 

bool guess()//判断确定好第一行按钮的状态后，推算第五行灯是否全熄灭   
{
	int r,c;
	for(r=1; r<5; r++)//根据 press第一行和 puzzle数组，计算 press其他行的值
		for(c=1; c<7; c++)
			press[r+1][c]=(press[r][c]+press[r][c-1]+press[r][c+1]+press[r-1][c]+puzzle[r][c])%2;
	for(c=1; c<7; c++)//判断所计算的 press数组能否熄灭第5行的所有灯
	{
		if(puzzle[5][c] != ((press[5][c-1]+press[5][c]+press[5][c+1]+press[4][c])%2))
			return false;
	}
	return true;	
} 

void enumerate()//枚举 将矩阵第一行看成一个二进制数从 000000 - 111111  (0-63) 共64种状态
{
	int c;
	for(c=1; c<7; c++)
		press[1][c]=0;
	while(guess()==false)//如果到最后一行时灯未全部熄灭(guess()==false)，则将第一行（第一行看成一个二进制数）进行++，换种状态进行枚举
	{
		press[1][6]++;
		c=6;
		while(press[1][c]>1)
		{
			press[1][c]=0;
			c--;
			press[1][c]++;
		}
	}
	return;
}

int main()
{
	//freopen("D:\\C++\\OpenJudge\\NOI\\in.txt","r",stdin);
	int r,c;
	for(r=0; r<6; r++)//第0列和第7列置为0
		press[r][0]=press[r][7]=0;
	for(c=1; c<7; c++)//第0行置为0
		press[0][c]=0;
	for(r=1; r<6; r++)
		for(c=1; c<7; c++)
			cin >> puzzle[r][c];
	enumerate();
	for(r=1; r<6; r++)
	{
		for(c=1; c<7; c++)
		{
			cout << press[r][c] << " ";
		}
		cout << endl;
	}
	return 0;
}
