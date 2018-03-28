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
#define MOD 1000000007
#define ios ios::sync_with_stdio(0);
#define N 24

int K[2] , a[N];
ll t[1<<N];

int main(){
    int n , k;
    sc(n);
    for(int i = 0 ; i < n ; i++)
        sc(a[i]);
    
    sc(k);
    for(int i = 0 ; i < k ; sc(K[i]) , i++);
    
    t[0] = 0;
    for(int i = 1 ; i < 1<< n ; i++){
        int j = __builtin_ctz(i);
        //cout << i << " " << j << endl;
        t[i] = t[i^(1<<j)] + a[j];
    }
    for(int i = 0 ; i < 1<< n ; i++)
        for(int j = 0 ; j < k ; j++)
            if( t[i] == K[j] ){
                t[i] = -1;
                break;
            }
    t[0] = 1;
    for(int i = 1 ; i < 1<<n ; i++)
        if( t[i] >= 0 ){
            t[i] = 0;
            for(int j = 0 ; j < n ; j++)if( i&(1<<j) ){
                t[i] += t[i^(1<<j)];
            }
            if( t[i] >= MOD ) t[i] %= MOD;
        }
        else t[i] = 0;
    
    cout << t[(1<<n)-1] << '\n';
    
    return 0;
}
