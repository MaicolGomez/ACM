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
#define inf 1000000001
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
#define N 10005

int A[N] , t[N];


int main(){
    int L1 , L2 , L3 , C1 , C2 , C3 , n , x , y;
    scanf("%d%d%d%d%d%d",&L1,&L2,&L3,&C1,&C2,&C3);
        sc(n);
        sc(x),sc(y);
        if( x > y )
            swap( x , y );
        for(int i = 2 ; i <= n ; i++)
            sc(A[i]);

        A[n+1] = inf;
        int l1 , l2 , l3;
        l1 = l2 = l3 = x;
            
        for(int i = x + 1 ; i <= y ; i++){
            t[i] = inf;
            while( A[i] - A[l1] > L1 ) l1++;
            while( A[i] - A[l2] > L2 ) l2++;
            while( A[i] - A[l3] > L3 ) l3++;
            //cout << i << " " << l1 << " " << l2 << " " << l3 << endl;
            t[i] = min( t[i] , t[l1] + C1 );
            t[i] = min( t[i] , t[l2] + C2 );
            t[i] = min( t[i] , t[l3] + C3 );
        }
        printf("%d\n",t[y]);
    return 0;
}
