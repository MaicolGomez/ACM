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
#define N 1005

int next[N][30] , node , term[N];

void add(char *s){
    int cur = 0 , len = strlen(s);
    for(int i = 0 ; i < len ; i++){
        if( next[cur][s[i] - 'a'] == 0 ) next[cur][ s[i] - 'a' ] = node++;
        cur = next[cur][s[i] - 'a'];
    }
    term[cur] = 1;
}

char s[10005] , a[N];
int len , t[10005][N];
int T[N];

void aho(){
    queue<int> Q;
    for(int i = 0 ; i < 26 ; i++){
        int v = next[0][i];
        if( v ) Q.push(v) , T[v] = 0;
    }
    while( !Q.empty() ){
        int u = Q.front(); Q.pop();
        for(int i = 0 ; i < 26 ; i++){
            int v = next[u][i] , x = next[T[u]][i];
            if( v == 0 ) next[u][i] = x;
            else T[v] = x , Q.push(v) , term[v] |= term[x];
        }
    }
}

int main(){
    int tc;
    sc(tc);
    while( tc-- ){
        node = 1;
        scanf("%s%s",s,a);
        me(next,0);
        me(term,0);
        add(a);
        aho();
        len = strlen(s);
        for(int i = 0 ; i < node ; i++)
            if( term[i] ) t[len][i] = inf;
            else t[len][i] = 0;
        
        for(int i = len - 1 ; i >= 0 ; i--){
            for(int j = node - 1 ; j >= 0 ; j--){
                if( term[j] ) t[i][j] = inf;
                else
                    t[i][j] = min( t[i+1][ next[j][ s[i] - 'a' ] ] , 1 + t[i+1][ j ] );
            }
        }
        printf("%d\n",t[0][0]);
    }
    return 0;
}
