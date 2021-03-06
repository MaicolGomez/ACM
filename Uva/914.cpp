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
#define N 1000000

bool prime[N+5];
vi v;

void sieve(){
    me( prime , 1 );
    prime[0] = prime[1] = 0;
    for(int i = 2 ; i * i <= N ; i++)
        if( prime[i] )
            for(int j = i*i ; j <= N ; j+=i)
                prime[j] = 0;
     v.pb(-1);
     for(int i = 2 ; i <= N ; i++)
        if( prime[i] ) v.pb( i );
        
    v.pb( N + 5 );
}

int main(){
    sieve();
    int l , h , tc;
    sc(tc);
    while( tc-- ){
        sc(l),sc(h);
        map<int,int> m;
        map<int,int> ::iterator it;
        for(int i = 1 ; i < v.size() ; i++){
            if( v[i] > h ) break;
            if( l <= v[i - 1] && v[i] <= h ) m[ v[i] - v[i-1] ]++;
        }
        int ans = 0 , maxi = -1 , res;
        for( it = m.begin() ; it != m.end() ; it++)
            if( (*it).se > maxi ) maxi = (*it).se , res = (*it).fi;
        for( it = m.begin() ; it != m.end() ; it++)
            if( (*it).se == maxi ) ans++;
        
        if( ans == 1 ) printf("The jumping champion is %d\n",res);
        else printf("No jumping champion\n");
        
    }
    return 0;
}
