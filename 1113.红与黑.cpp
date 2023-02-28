#include<iostream>
#include<cstring>
#include<queue>
#define x first
#define y second

using namespace std;
typedef pair<int,int> PII;

const int N=30;

char g[N][N];
int n,m;
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
bool st[N][N];

int bfs(int x,int y)
{
    int cnt=1;
    queue<PII> q;
    q.push({x,y});
    while(q.size())
    {
        PII t=q.front();
        q.pop();
        int x=t.x,y=t.y;
        for(int i=0;i<4;i++)
        {
            int a=x+dx[i],b=y+dy[i];
            if(a<0 || a>=n || b<0 || b>=m) continue;
            if(st[a][b]) continue;
            if(g[a][b]!='.') continue;
            st[a][b]=true;
            q.push({a,b});
            cnt++;
        }
    }
    return cnt;
}


int main()
{
    while(cin>>m>>n,n||m)
    {
        memset(st,0,sizeof st);
        for(int i = 0;i < n;i++) scanf("%s",g[i]);
        int x,y,flag=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                if(g[i][j]=='@')
                {
                    x=i,y=j;
                    flag=1;
                }
            if(flag) break;
        }
        cout<< bfs(x,y) <<endl;
    }
    return 0;
}

