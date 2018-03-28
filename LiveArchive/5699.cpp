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
#define MOD 1000000007
#define ios ios::sync_with_stdio(0);
#define N 10*1005

int next[N][4] , T[N] , term[N] , node , S[N];

string dna = "ACGT";

int get(char x){
    for(int i = 0 ; i < 4 ; i++)
        if( dna[i] == x ) return i;
}

void add(char *s,int x){
    int ac = 0, len = strlen(s);
    for(int i = 0 ; i < len ; i++){
        if( next[ac][get(s[i])] == 0 ) next[ac][get(s[i])] = node++;
        ac = next[ac][get(s[i])];
    }
    term[ac] |= (1<<x);
}

void aho(){
    queue<int> Q;
    for(int i = 0 ; i < 4 ; i++){
        int v = next[0][i];
        if( v ) Q.push(v) , T[v] = 0;
    }
    while( !Q.empty() ){
        int u = Q.front(); Q.pop();
        for(int i = 0 ; i < 4 ; i++){
            int v = next[u][i] , x = next[T[u]][i];
            if( v == 0 ) next[u][i] = x;
            else Q.push(v) , T[v] = x , term[v] |= term[x];
        }
    }
}

int len , t[2][1005][1025];//Live Archive AC con recursion y memoria 100*1000^2

int f(int x,int cur,int mask){
    if( x == len ) return S[mask|term[cur]];
    int &ret = t[x][cur][mask];
    if( ret != -inf ) return ret;
    ret = -inf;
    for(int i = 0 ; i < 4 ; i++)
        ret = max( ret , f( x + 1 , next[cur][i] , mask|term[cur] ) );
    return ret;
}

int main(){
    int n , x[12];
    while( scanf("%d%d",&n,&len) == 2 and n ){
        me(next,0);
        me(term,0);
        me(T,0);
        node = 1;
        char s[105];
        for(int i = 0 ; i < n ; i++){
            scanf("%s %d",s,&x[i]);
            add(s , i);
        }
        aho();
        for(int i = 0 ; i < 1<<n ; i++){
            int q = 0;
            for(int j = 0 ; j < n ; j++)if( i&(1<<j) ) q += x[j];
            S[i] = q;
        }
        
                  
        for(int cur = 0 ; cur < node ; cur++) // HDU no pasa memoria y probablemente tampoco en tiempo, asi que pase a iterativo
            for(int mask = 0 ; mask < 1<<n ; mask++)
                t[len&1][cur][mask] = S[mask|term[cur]];
        
        
        
        for(int x = len - 1 ; x >= 0 ; x--){
            for(int cur = 0 ; cur < node ; cur++){
                for(int mask = 0 ; mask < 1<<n ; mask++){
                    t[x&1][cur][mask] = -inf;
                    for(int i = 0 ; i < 4 ; i++)
                        t[x&1][cur][mask] = max( t[x&1][cur][mask] , t[!(x&1)][next[cur][i]][mask|term[cur]] );
                }
            }
        }
        
        
        
        int ans = t[0][0][0];
        if( ans >= 0 ) printf("%d\n",ans);
        else printf("No Rabbit after 2012!\n");
    }
    return 0;
}
