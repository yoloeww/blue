#include<iostream>
#include<cstdio>
#include<cstring> 
using namespace std;
int GetBit(char c,int i)//取c的第i位 
{
	return (c >> i) & 1;
}

void SetBit(char & c,int i,int v)//设置c的第i位为v 
{
	if(v)
		c |= (1 << i);
	else
		c &= ~(1 << i); 
}

void Flip(char & c,int i)//将c的第i位取反 
{
	c ^= (1 << i);
}

void Output(char result[])//输出结果 
{
	for(int r=0; r<5; r++)
	{
		for(int c=0; c<6; c++)
		{
			cout << GetBit(result[r],c) << " ";
		}
		cout << endl;
	}
}

int main()
{
	//freopen("D:\\C++\\OpenJudge\\NOI\\in.txt","r",stdin);
	char orilights[5];//最初灯矩阵，一个比特表示一盏灯 
	char lights[5];//不停变化的灯矩阵 
	char result[5];//最后计算的结果按钮矩阵 
	char buttons;//某一行的（按钮）开关状态 
	memset(orilights,0,sizeof(orilights));
	for(int r=0; r<5; r++)//读入最初灯状态 
		for(int c=0; c<6; c++)
		{
			int v;
			cin >> v;
			SetBit(orilights[r],c,v);
		}
	for(int n=0; n<64; n++)//遍历首行开关的64种状态，从 000000 - 111111
	{
		memcpy(lights,orilights,sizeof(orilights));
		buttons=n;//首行开关状态 
		for(int r=0; r<5; r++)
		{
			result[r]=buttons;//第i行的开关方案 
			for(int c=0; c<6; c++)
			{
				if(GetBit(buttons,c))
				{
					if(c>0)
						Flip(lights[r],c-1);//改左灯 
					if(c<5)
						Flip(lights[r],c+1);//改右灯 
					Flip(lights[r],c);//改开关位置的灯 
				}
			}
			if(r<4)
			{
				lights[r+1] ^= buttons;//改下一行的灯  
			}
			buttons = lights[r];//第i+1行开关方案和第i行灯情况相同
		}
		if(lights[4]==0)//如果第5行灯全熄灭也就是全为0，那么就输出result
		{
			Output(result);
			break;
		}
	}
	return 0;
}
