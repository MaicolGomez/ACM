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
#define N 100005

struct tree{
    int maxi , mini , flag;
    tree(){}
};

tree T[4*N];

void push(int node,int x,int y){
    if( T[node].flag ){
        T[node].maxi += T[node].flag;
        T[node].mini += T[node].flag;
        if( x != y ) T[L(node)].flag += T[node].flag , T[R(node)].flag += T[node].flag;
    }
    T[node].flag = 0;
}

void update(int node,int x,int y,int a,int b,int val){
    push(node,x,y);
    if( y < a || b < x ) return;
    //cout << node << " " << x << " " << y << " " << a << " " << b << " " << val << endl;
    if( a <= x && y <= b ){
        T[node].flag += val;
        push( node , x , y );
        return;
    }
    update( L(node) , x , M(x,y) , a , b , val );
    update( R(node) , M(x,y) + 1 , y , a , b , val );
    T[node].maxi = max( T[L(node)].maxi , T[R(node)].maxi );
    T[node].mini = min( T[L(node)].mini , T[R(node)].mini );
}

tree query(int node,int x,int y,int a,int b){
    push(node,x,y);
    if( a <= x && y <= b )
        return T[node];
    
}

int main(){
    freopen("stones.in","r",stdin);
    freopen("stones.out","w",stdout);
    int n , x , p;
    sc(n);
    for(int i = 0 ; i < n ; i++){
        scanf("%d%d",&x,&p);
        update( 0 , 0 , n - 1 , 0 , x - 1 , ((p==1)?1:-1) );
        tree q = query( 0 , 0 , n - 1 , 0 , n - 1 );
        //cout << q.maxi << " " << q.mini << endl;
        if( q.maxi > 0 && q.mini >= 0 ) printf(">\n");
        else if( q.maxi <= 0 && q.mini < 0 ) printf("<\n");
        else printf("?\n");
    }
    
    return 0;
}
