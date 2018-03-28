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
#define LEN 700

int A[N] , seg[N] , n;

int findvalue(int lo,int hi,int x){
    if( seg[lo] == x ) return lo;
    if( seg[hi] == x ) return hi;
    while( hi - lo > 1 ){
        int mid = M(lo,hi);
        if( seg[mid] <= x ) lo = mid;
        else hi = mid;
    }
    return lo;
}

void insert(int st,int en,int x,int y,int r){
    seg[r] = A[x] = y;
    for(int i = r ; i + 1 <= en && seg[i] > seg[i+1] ; i++) swap( seg[i] , seg[i+1] );
    for(int i = r ; i - 1 >= st && seg[i] < seg[i-1] ; i--) swap( seg[i] , seg[i-1] );
}


int find(int lo,int hi,int x){
    if( seg[lo] > x ) return 0;
    if( seg[hi] <= x ) return LEN;
    int r = lo;
    while( hi - lo > 1 ){
        int mid = M(hi,lo);
        if( seg[mid] <= x ) lo = mid;
        else hi = mid;
    }
    return lo - r + 1;
}

int main(){
    int q;
    sc(n),sc(q);
    for(int i = 0 ; i < n ; i++)
        sc(A[i]) , seg[i] = A[i];
    
    for(int i = 0 ; i < n ; i++){
        int j = min( i + LEN , n );
        sort( seg + i , seg + j );
        i = j - 1;
    }
    char s[2];
    int x , y , st , en;
    while( q-- ){
        scanf("%s",s);
        if( s[0] == 'M' ){
            scanf("%d %d",&x,&y); x--;
            int k = x / LEN;
            st = k * LEN , en = min( (k+1) * LEN , n ) - 1;
            int r = findvalue( st , en , A[x] );
            insert( st , en , x , y , r );
        }
        else{
            int k;
            scanf("%d %d %d",&x,&y,&k); x--,y--;
            st = x/LEN , en = y/LEN;
            if( st == en ){
                int ans = 0;
                for(int i = x ; i <= y ; i++)
                    ans += A[i]<=k;
                printf("%d\n",ans);
            }
            else{
                int ans = 0;
                for(int i = x ; i < min((st+1)*LEN , n) ; i++) ans += A[i]<=k;
                for(int i = en*LEN ; i <= y ; i++) ans += A[i]<=k;
                for(int i = st + 1 ; i <= en - 1 ; i++) ans += find( i*LEN , min( (i+1)*LEN - 1 , n - 1 ) , k );
                printf("%d\n",ans);
            }
        }
    }
    return 0;
}
