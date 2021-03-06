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
#define N 1000005

int k , l , m , t[N];

int main(){
    int n;
    sc(k),sc(l),sc(m);
    t[0] = 0;
    for(int i = 1 ; i <= 1000000 ; i++){
        t[i] = 0;
        if( t[i-1] == 0 ) t[i] = 1;
        if( i - l >= 0 && t[i-l] == 0 ) t[i] = 1;
        if( i - k >= 0 && t[i-k] == 0 ) t[i] = 1;
    }
    for(int i = 0 ; i < m ; i++){
        sc(n);
        if( t[n] ) printf("A");
        else printf("B");
    }
    printf("\n");
    return 0;
}
