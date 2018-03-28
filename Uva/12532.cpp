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
#define N 100005

struct Tree{
    int neg , zero;
    Tree(){}
    Tree(int Neg ,int Z){
        neg = Neg , zero = Z;
    }
};

Tree T[4 * N];
int n , A[N];

void init(int node,int a ,int b){
    if( a == b ){
        T[node].zero = T[node].neg = 0;
        if( A[a] == 0 ) T[node].zero = 1;
        else T[node].neg = (A[a]<0);
        //cout << a << " " << T[a].zero << " " << T[a].neg << endl;
        return;
    }
    int mid = (a+b)/2;
    init( 2 * node + 1 , a , mid );
    init( 2 * node + 2 , mid + 1 , b );
    T[node].zero = T[ 2 * node + 1 ].zero + T[ 2 * node + 2 ].zero; 
    T[node].neg = T[ 2 * node + 1 ].neg + T[ 2 * node + 2 ].neg; 
}

void update(int node, int a ,int b, int x,int val){
    if( x < a || b < x ) return;
    if( a == b ){
        T[node].zero = T[node].neg = 0;
        if( val == 0 ) T[node].zero = 1;
        else T[node].neg = (val<0);
        return;
    }
    int mid = (a+b)/2;
    update( 2 * node + 1 , a , mid , x , val );
    update( 2 * node + 2 , mid + 1 , b , x , val );
    T[node].zero = T[ 2 * node + 1 ].zero + T[ 2 * node + 2 ].zero; 
    T[node].neg = T[ 2 * node + 1 ].neg + T[ 2 * node + 2 ].neg;
}

Tree V(0,0);

Tree query(int node ,int a,int b,int x,int y){    
    if( y < a || b < x ) return V;
    if( x <= a && b <= y )
        return T[node];
    
    int mid = (a + b)/2;
    
    Tree p = query( 2 * node + 1 , a , mid , x , y );
    Tree q = query( 2 * node + 2 , mid + 1 , b , x , y );
    
    return Tree( p.neg + q.neg , p.zero + q.zero );
}

int main(){
    ios::sync_with_stdio(0);
    int k;
    while( cin >> n >> k ){
        for(int i = 0 ; i < n ; i++)
            cin >> A[i];
        
        init( 0 , 0 , n - 1 );
        char c;
        int x , y;
        Tree r = query( 0 , 0 , n - 1 , 0 , 0 );
        for(int i = 0 ; i < k ; i++){
            cin >> c >> x >> y;
            if( c == 'C' ){
                x--;
                update( 0 , 0 , n - 1 , x , y );
            }
            else{
                x--,y--;
                Tree ans = query( 0 , 0 , n - 1 , x , y );
                if( ans.zero > 0 ) cout << 0;
                else if( ans.neg & 1 ) cout << "-";
                else cout << '+';
            }
        }
        cout << "\n";
    }
    
    return 0;
}
