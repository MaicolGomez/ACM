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
#define N 10000

vi A[N+2];
int R[N+2];

int main(){
    int tc;
    sc(tc);
    while(tc--){
        int n , C , x;
        sc(C) , sc(n);
        for(int i = 0 ; i < C + 2 ; i++)
            A[i].clear();
        for(int i = 1 ; i <= n ; i++){
            sc(x);
            R[i] = x;
            if( x > C ) continue;
            A[x].pb(i);
        }
        for(int i = 1 ; i <= n ; i++){
            if( R[i] >= C ) continue;
            int g = C - R[i];
            if( A[g].size() ){
                int pos = 0;
                if( g == R[i] ) pos++;
                for(int j = pos ; j < A[g].size() ; j++){
                    printf("%d %d\n", i , A[g][j] );
                    goto xx;
                }
            }
        }
        xx:;
    }
    return 0;
}
