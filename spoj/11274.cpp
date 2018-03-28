#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
#include<deque>
#include<map>
#include<set>
#include<string>
#include<climits>
#include<sstream>
#include<queue>
using namespace std;
#define inf (1<<29)
#define ll long long
#define vi vector<int>
#define all(v) v.begin() , v.end()
#define sc(x) scanf("%d",&x)
#define me(t,val) memset( t , val , sizeof(t) )
#define pb(x) push_back(x)
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define fi first
#define se second
#define L(x) ((x<<1)+ 1)
#define R(x) L(x)+1
#define M(x,y) ((x+y)>>1)
#define N 55
#define MOD 1000000007

int n , a[N][N];
int A[N*N];

#define MAX_V1 55
#define MAX_V2 55
#define MAX_E N*N
  
int V1,V2,l[MAX_V1],r[MAX_V2]; 
int E,to[MAX_E],next[MAX_E],last[MAX_V1] , state[MAX_E];
bool visited[MAX_V1];
 
void init(){ 
    memset(last,-1,sizeof(int)*V1);
    E = 0; 
} 
   
void add_edge(int u, int v){
    to[E] = v, next[E] = last[u]; last[u] = E; state[E] = 0 , ++E;
}

bool pairup(int u){ 
    if (visited[u])  return false; 
    visited[u] = true; 
      
    for(int e = last[u];e!=-1;e = next[e]){
        if( state[e] == 0 ) continue;
        int v = to[e]; 
          
        if(r[v]==-1 || pairup(r[v])){ 
            l[u] = v;
            r[v] = u;
            return true; 
        } 
    } 
      
    return false; 
} 
  
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

int main(){
    int tc;
    sc(tc);
    while( tc-- ){
        sc(n);
        int m = 0;
        map< int , pair< int , pii > > M;
        for(int i = 0 ; i < n ; i++)
            for(int j = 0; j < n ; j++)
                sc(a[i][j]) , A[m++] = a[i][j];
        
        sort( A , A + m );
        V1 = n , V2 = n;
        init();

        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < n ; j++)
                add_edge( i , j ) ,  M[ a[i][j] ] = mp( E - 1 , mp( i , j) );
        
        int match = hopcroft_karp();
        int lo = 0 , hi = 0;
        int ans = INT_MAX;
        
        state[ M[ A[0] ].fi ] = 1;
        while( lo < m ){
            if( hi == m ) break;
            while( hi < m and match < n ){
                hi++;
                if( hi < m ){
                    state[ M[ A[hi] ].fi ] = 1;
                    int x = M[ A[hi] ].se.fi;
                    memset(visited,false,sizeof(bool)*V1);
                    bool change = 1;
                    while(change and hi - lo >= n ){ 
                        change = false; 
                        memset(visited,false,sizeof(bool)*V1); 
                          
                        for(int i = 0;i<V1;++i) 
                            if( l[i] == -1 and pairup(i) ) change = 1 , match++;

                    }
                    
                }
            }
            if( hi < m ) ans = min( ans , A[hi] - A[lo] );
            state[ M[ A[lo] ].fi ] = 0;
            int x = M[ A[lo] ].se.fi , y = M[ A[lo] ].se.se;
            if( l[x] != -1 and l[x] == y ){
                match-- ;
                r[ l[x] ] = -1;
                l[x] = -1;
            }
            memset(visited,false,sizeof(bool)*V1);
                    bool change = 1;
                    while(change){ 
                        change = false; 
                        memset(visited,false,sizeof(bool)*V1); 
                          
                        for(int i = 0;i<V1;++i) 
                            if( l[i] == -1 and pairup(i) ) change = 1 , match++;

                    }
            lo++;
        }
        printf("%d\n",ans);
    }
}

