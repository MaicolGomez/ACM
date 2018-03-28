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
#define MOD 10009
#define ios ios::sync_with_stdio(0);
#define N 1001

int A[N] , m;

int getmin(int n,int *a){
    int ans = 0;
    sort( a , a + m );
    for(int i = 0 ; i < m ; i++){
        if( n ){
            if( a[i] <= n ){
                n -= a[i];
                ans += a[i] * ( a[i] + 1 ) / 2;
            }
            else{
                n = a[i] - n;
                ans += a[i] * ( a[i] + 1 ) / 2 - n * (n + 1) / 2;
                break;
            }
        }
        else break;
    }
    return ans;
}

int getmax(int n,int *a){
    int ans = 0;
    while( n ){
        sort( a , a + m );
        ans += a[m-1];
        a[m-1]--;
        n--;
    }
    return ans;
}

int main(){
    int n;
    while( cin >> n >> m ){
        for(int i = 0 ; i < m ; i++)
            cin >> A[i];
        
        int mini = getmin( n , A );
        int maxi = getmax( n , A );
        cout << maxi << " " << mini << '\n';
    }
    return 0;
}
