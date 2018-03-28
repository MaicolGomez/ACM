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
#include<climits>
#include<string>
#include<stack>
#include<sstream>
using namespace std;
#define pi (2.0*acos(0.0))
#define eps 1e-6
#define ll long long
#define inf (1<<29)
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
#define L(x) ((x<<1) + 1)
#define R(x) ((x<<1) + 2)
#define M(x,y) ((x+y)>>1)
#define fi first
#define se second
#define MOD 10009
#define N 200005

struct nodo{
  int fil;
  int col;
};

bool visited[101][101];
int dx[4]={0,-1,0,1};
int dy[4]={-1,0,1,0};
int m[101][101];
int n;

void bfs( nodo source , int color ){
    deque <nodo> Q;
    Q.push_back(source);
    while(!Q.empty()){
     nodo q=Q.front();
     Q.pop_front();
       for(int i=0;i<4;i++){
          nodo p;
          if( q.fil+dx[i]<n && q.fil+dx[i]>=0 && q.col+dy[i]>=0 && q.col+dy[i]<n && visited[q.fil+dx[i]][q.col+dy[i]] == 0 && m[q.fil+dx[i]][q.col+dy[i]] == color ){
            p.fil= q.fil+dx[i];
            p.col= q.col+dy[i];
            visited[p.fil][p.col]=1;
            Q.push_back(p);
          }         
       }        
    }    
}

int main(){
    int a,b;
    char s[1000];
     while( sc(n) && n ){
          getchar();
          memset(visited, 0, sizeof(visited));
        for(int i=0;i<n;i++)for(int j=0;j<n;j++) m[i][j]=n;
          
        for(int i=0;i<n-1;i++){
            gets(s);
            stringstream in(s);
            while( in >> a >> b ){
                m[a-1][b-1] = i+1;
            }
          
        }

          int cont=0;
          for(int i=0;i<n;i++)
             for(int j=0;j<n;j++){
                int color=m[i][j];    
                nodo k;
                k.fil=i;
                k.col=j;
                if( visited[i][j] == 0 ){ cont++; bfs(k,color); }     
            }   
          if(cont==n) cout<<"good"<<endl;
          else  cout<<"wrong"<<endl;
             
     }    
}
