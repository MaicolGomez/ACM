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
#define M(x,y) (x+y)>>1
#define fi first
#define se second
#define MOD 10009
#define ios ios::sync_with_stdio(0);
#define N 500001

int n , a[N] , b;

bool f(int x){
    int S = 0;
    for(int i = 0 ; i < n ; i++)
        S += (a[i] + x - 1) / x;
    
    return S <= b;
}

int main(){
    char s[100];
    while( scanf("%d%d",&n,&b) == 2 and ( n != -1 or b != -1 ) ){
        getchar();
        for(int i = 0 ; i < n ; i++){
            gets(s);
            a[i] = atoi(s);
        }
            //sc(a[i]);
            
        int lo = 0 , hi = 5000002;
        
        while( lo + 1 < hi ){
            int mid = M(lo,hi);
            if( f(mid) ) hi = mid;
            else lo = mid;
        }
        printf("%d\n",hi);
        
    }
    return 0;
}
