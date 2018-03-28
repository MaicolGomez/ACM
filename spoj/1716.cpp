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
#define fi first
#define se second
#define MOD 10009
#define N 50005

struct Tree{
    int best , s , l , r;
    Tree(){}
    Tree(int Best , int S,int L,int R){
        best = Best;
        s = S;
        l = L;
        r = R;
    }
};

int n , A[N];
Tree T[ 4 * N ];

void init(int node,int l , int r){
    if( l == r ){
        T[node].best = A[l];
        T[node].s = A[l];
        T[node].l = A[l];
        T[node].r = A[l];
        //cout << l << " " << node << " : " << T[node].s << " " << T[node].l << " " << T[node].r << " " << T[node].best << endl;
        return;
    }
    int mid = (l+r)/2 , a = 2 * node + 1 , b = 2 * node + 2;
    init( a , l , mid );
    init( b , mid + 1 , r );
    T[node].l = max( T[a].l , T[a].s + T[b].l );
    T[node].r = max( T[b].r , T[b].s + T[a].r );
    T[node].s = T[a].s + T[b].s;
    T[node].best = max( T[a].best , T[b].best );
    T[node].best = max( T[node].best , T[a].r + T[b].l );
    //cout << node << " : " << T[node].s << " " << T[node].l << " " << T[node].r << " " << T[node].best << endl;
}

Tree V( -inf , -inf , -inf , -inf );

Tree query(int node ,int l, int r, int x, int y){
    //cout << l << " " << r << " -- " << x << " " << y << endl;
    if( r < x || y < l ) return V;
    if( x <= l && r <= y )
        return T[node];
    
    int mid = (l + r) / 2 , a = 2 * node + 1 , b = 2 * node + 2;
    Tree p = query( a , l , mid , x , y );
    Tree q = query( b , mid + 1 , r , x , y );
    if( p.best == -inf ) return q;
    else if( q.best == -inf ) return p;
    else if( p.best != -inf && q.best != -inf ){
        Tree ans;
        ans.s = p.s + q.s;
        ans.l = max( p.s + q.l , p.l );
        ans.r = max( p.r + q.s , q.r );
        ans.best = max( p.best , q.best );
        ans.best = max( ans.best , p.r + q.l );
        return ans;
    }
}

void update( int node , int l , int r , int x , int val ){
    if( r < x || x < l ) return;
    if( l == r ){
        T[node].best = val;
        T[node].s = val;
        T[node].l = val;
        T[node].r = val;
        return;
    }
    int mid = (l+r)/2 , a = 2 * node + 1 , b = 2 * node + 2;
    update( a , l , mid , x , val );
    update( b , mid + 1 , r , x , val );
    T[node].l = max( T[a].l , T[a].s + T[b].l );
    T[node].r = max( T[b].r , T[b].s + T[a].r );
    T[node].s = T[a].s + T[b].s;
    T[node].best = max( T[a].best , T[b].best );
    T[node].best = max( T[node].best , T[a].r + T[b].l );
}

int main(){
    sc(n);
    for(int i = 0 ; i < n ; i++)
        sc(A[i]);
    
    init( 0 , 0 , n - 1 );
    
    int q , c , x , y;
    
    sc(q);
    for(int i = 0 ; i < q ; i++){
        sc(c) , sc(x) , sc(y) ;
        if( c ){
            x--,y--;
            printf("%d\n", query( 0 , 0 , n - 1 , x , y ).best );
        }
        else{
            x--;
            update( 0 , 0 , n - 1 , x , y );
        }
    }
    return 0;
}
