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
#define N 200000

struct tree{
    int mini , flag;
    tree(){}
};

int n , C , princess[N+5] , next[N+5] , F[N+5] , K[N+5];
tree T[4*N];

void init(int node,int a,int b){
    if( a == b ){
        T[node].flag = 0;
        T[node].mini = F[a];
        return;
    }
    int v1 = L(node) , v2 = R(node);
    init( v1 , a , M(a,b) );
    init( v2 , M(a,b) + 1 , b );
    T[node].flag = 0;
    T[node].mini = min( T[v1].mini , T[v2].mini );
}

void push(int node,int a,int b){
    if( T[node].flag ){
        T[node].mini += T[node].flag;
        if( a != b ) T[L(node)].flag += T[node].flag , T[R(node)].flag += T[node].flag;
    }
    T[node].flag = 0;
}

int query(int node,int a,int b,int x,int y){
    push( node , a , b );
    if( b < x || y < a ) return inf;
    if( x <= a && b <= y )
        return T[node].mini;
    
    int v1 = L(node) , v2 = R(node);
    return min( query( v1 , a , M(a,b) , x , y ) , query( v2 , M(a,b) + 1 , b , x , y ) );
}

void update(int node,int a,int b,int x,int y,int val){
    push(node,a,b);
    if( b < x || y < a ) return;
    if( x <= a && b <= y ){
        T[node].flag += val;
        push( node , a , b );
        return;
    }
    int v1 = L(node) , v2 = R(node);
    update( v1 , a , M(a,b) , x , y , val );
    update( v2 , M(a,b) + 1 , b , x , y , val );
    T[node].mini = min( T[v1].mini , T[v2].mini );
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    while( sc(n) == 1 ){
        char c;
        int x;
        vector< pair<int,int> > A;
        A.clear();
        map<int , int> m;
        C = 0;
        me(princess,-1);
        for(int i = 2 ; i <= n ; i++){
            cin >> c >> x;
            if( c == 'd' ) A.pb( mp( x , i ) );
            else{
                princess[i] = x;
                m[i] = C++;
            }
        }
        int last = -1;
        for(int i = n - 1 ; i >= 1 ; i--){
            if( princess[i] != -1 ) last = i;
            next[i] = last;
        }
        int mini = (1<<30);
        int k = C - 2;
        for(int i = n - 1 ; i >= 1 ; i--)
            if( princess[i] != -1 ){
                mini = min( mini , princess[i] );
                F[k] =  mini , k--;
            }
        C--;
        sort( all(A) );
        /*for(int i = 0 ; i < C ; i++)
            cout << F[i] << " - ";
        cout << endl;*/
        init( 0 , 0 , max( 0 , C - 1) );
        int ans = 0 , kill = 0;
        for(int i = A.size() - 1 ; i >= 0 ; i--){
            //cout << A[i].fi << " " << A[i].se << endl;
            int pos = A[i].se;
            if( next[pos] == -1 ){
                ans += A[i].fi;
                K[kill++] = pos;
            }
            else{
                int g = m[ next[pos] ];
                //cout << g << " -- " << query( 0 , 0 , C - 1 , g , C - 1 ) << endl;
                if( query( 0 , 0 , C - 1 , g , C - 1 ) > 1 ){
                    update( 0 , 0 , C - 1 , g , C - 1 , -1);
                    ans += A[i].fi;
                    K[kill++] = pos;
                }
            }
        }
        if( kill >= princess[n] ){
            cout << ans << '\n';
            cout << kill << '\n';
            sort( K , K + kill );
            for(int i = 0 ; i < kill ; i++){
                if( i ) printf(" ");
                printf("%d",K[i]);
            }
            printf("\n");
        }
        else cout << -1 << '\n';
    }
    return 0;
}
