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
#include<string>
#include<stack>
#include<sstream>
using namespace std;
#define pi (2.0*acos(0.0))
#define inf 2000000000
#define eps 1e-8
#define ll long long
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
#define N 10005
#define MOD 10009

bool ok[N];

int BinarySearch(int x,int n){
    int p, q, i, L;

    p = 0;   /* Left border of the search  */
    q = n-1; /* Right border of the search */
    L = 0;   /* Comparison counter         */
    while (p <= q) {
        i = (p + q) / 2;
        ++L;
        if ( i == x) 
            return L;
        
        if( x < i )
            q = i - 1;
        else
            p = i + 1;
    }
    return -1;
}

int main(){
    int I , L;
    cin >> I >> L;
    for(int n = I + 1 ; n <= 10000 ; n++){
        int l = BinarySearch( I , n );
        ok[n] = (l==L);
    }
    int ans = 0;
    for(int i = 0 ; i <= 10000 ; i++)
        ans += (ok[i] && !ok[i+1] );
    
    printf("%d\n",ans);
    
    for(int i = 1 ; i <= 1000 ; i++){
        if( !ok[i] && ok[i+1] )
            cout << i+1 ;
        if( ok[i] && !ok[i+1] )
            cout << " " << i << endl;
    }
}