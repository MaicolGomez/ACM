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
#define inf (1<<30)
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
#define N 230005

struct tree{
    int pos , v , x , y , type;
    tree(){}
};

bool operator<(tree A,tree B){
    if( A.v != B.v ) return A.v > B.v;
    return A.type > B.type;
}


tree T[N] ;
int t[N];

int query(int x){
    int ans = 0;
    while( x ){
        ans += t[x];
        x -= (x&-x);
    }
    return ans;
}

void update(int x){
    while( x <= N-5 ){
        t[x]++;
        x += (x&-x);
    }
}

int ans[N];

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0 ; i < n ; i++)
        scanf("%d",&T[i].v) , T[i].pos = i + 1 , T[i].type = 0;
    
    int q;
    sc(q);
    for(int i = n ; i < n + q ; i++){
        sc(T[i].x),sc(T[i].y),sc(T[i].v);
        T[i].pos = i - n , T[i].type = 1;
    }
    sort( T , T + n + q );
    for(int i = 0 ; i < n + q ; i++){
        if( T[i].type == 0 ) update( T[i].pos );
        else ans[ T[i].pos ] =  query( T[i].y ) - query( T[i].x - 1 );
    }
    for(int i = 0 ; i < q ; i++)
        printf("%d\n",ans[i]);
    return 0;
}

