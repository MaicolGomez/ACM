#include<bits/stdc++.h>
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
#define M(x,y) ((x+y)>>1)
#define fi first
#define se second
#define MOD 1000000007
#define ios ios::sync_with_stdio(0);
#define N 105

int R[N][N] , C[N][N] , n;
char s[N][N];

#define MAX_V1 50001
#define MAX_V2 50001
#define MAX_E 1005536
  
int V1,V2,l[MAX_V1],r[MAX_V2]; 
int E,to[MAX_E],next[MAX_E],last[MAX_V1]; 
bool visited[MAX_V1];
 
void init(){ 
    memset(last,-1,sizeof(int)*V1); 
    E = 0; 
} 
   
void add_edge(int u, int v){ 
    to[E] = v, next[E] = last[u]; last[u] = E; ++E; 
}

bool pairup(int u){ 
    if (visited[u])  return false; 
    visited[u] = true; 
      
    for(int e = last[u];e!=-1;e = next[e]){ 
        int v = to[e]; 
          
        if(r[v]==-1 || pairup(r[v])){ 
            l[u] = v; 
            r[v] = u; 
            return true; 
        } 
    } 
      
    return false; 
} 
  /////////////////////////////////////IMPORTANTE definir V1 y V2
int hopcroft_karp(){ 
    bool change = true; 
    memset(l,-1,sizeof(int)*V1); 
    memset(r,-1,sizeof(int)*V2); 
      
    while(change){ 
        change = false; 
        memset(visited,false,sizeof(bool)*V1); 
          
        for(int i = 0;i<V1;++i) 
            if(l[i]==-1) change |= pairup(i); 
    } 
      
    int ret = 0; 
    for(int i = 0;i<V1;++i) 
        if(l[i]!=-1) ++ret; 
      
    return ret; 
}

int dx[4] = { 1 , -1 , 0 , 0 };
int dy[4] = { 0 , 0 , 1 , -1 };

bool good(int u,int n){
    return u >= 0 and u < n;
}

int main(){
    while( ~sc(n) ){
        for(int i = 0 ; i < n ; i++)
            scanf("%s",s[i]);
        
        V1 = 0 , V2 = 0;
        for(int i = 0 ; i < n ; i++){
            int j = 0;
            while( j < n ){
                if( s[i][j] == 'X' ) j++;
                else{
                    while( j < n and s[i][j] == '.' ){
                        R[i][j++] = V1;
                    }
                    V1++;
                }
            }
        }
        for(int j = 0 ; j < n ; j++){
            int i = 0;
            while( i < n ){
                if( s[i][j] == 'X' ) i++;
                else{
                    while( i < n and s[i][j] == '.' ){
                        C[i++][j] = V2;
                    }
                    V2++;
                }
            }
        }
        init();
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++)if( s[i][j] == '.' ){
                for(int k = 0 ; k < 4 ; k++){
                    int u = i , v = j;
                    while( good( u , n ) and good( v , n ) and s[u][v] == '.' ){
                        add_edge( R[i][j] , C[u][v] );
                        u += dx[k] , v += dy[k];
                    }
                }
            }
        }
        printf("%d\n",hopcroft_karp());
        
    }
    return 0;
}
