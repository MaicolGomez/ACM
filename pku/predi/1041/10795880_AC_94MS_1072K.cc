#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
#include<climits>
#include<set>
#include<deque>
#include<queue>
#include<map>
#include<string>
#include<sstream>
using namespace std;
#define pi (2.0*acos(0.0))
#define inf 2000000000
#define eps 1e-6
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define sc(x) scanf("%d",&x)
#define scl(x) scanf("%lld",&x)
#define all(v) v.begin() , v.end()
#define me(a,val) memset( a , val ,sizeof(a) )
#define pb(x) push_back(x)
#define pii pair<int,int> 
#define mp(a,b) make_pair(a,b)
#define Q(x) (x) * (x)
#define fi first
#define se second
#define MOD 10009
#define N 1000005
 
int maps[46][1996];
int jointNum[46];int flag;int visit[1996];int streeMx;
int stack[1996];int top;
 
void dfs(int home)
{
        for(int i=1;i<=streeMx;i++)
        {
                if(maps[home][i]!=0&&visit[i]==0)
                {
                        visit[i]=1;
                        dfs(maps[home][i]);
                        stack[top++]=i;
                }
        }
}
 
int main()
{
        int x,y,z;
        while(scanf("%d%d",&x,&y))
        {
                if(x==0&&y==0)
                        break;
                memset(maps,0,sizeof(int)*46*1996);memset(jointNum,0,sizeof(int)*46);
                memset(visit,0,sizeof(int)*1996);memset(stack,0,sizeof(int)*1996);
                top=0;
                scanf("%d",&z);maps[x][z]=y;maps[y][z]=x;jointNum[x]++;jointNum[y]++;
                streeMx=z;
                while(scanf("%d%d",&x,&y))
                {
                        if(x==0&&y==0)
                                break;
                        scanf("%d",&z);
                        maps[x][z]=y;maps[y][z]=x;jointNum[x]++;jointNum[y]++;
                        streeMx=max(z,streeMx);
                }
                int i;
                for(i=1;i<=45;i++)
                {
                        if(jointNum[i]%2!=0)
                                break;
                }
                if(i<=45)
                {
                        printf("Round trip does not exist.\n");
                }
                else
                {
                        dfs(1);
                        for(int j=top-1;j>=1;j--)
                                printf("%d ",stack[j]);
                        printf("%d\n",stack[0]);
                }
        }
 
        return 0;
}