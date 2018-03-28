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
#define N 10005

int a[N] , b[N];

int val(int n){
    int r = a[0];
    //cout << r << " ::: " << endl;
    for(int i = 0 ; i < n ; i++)
        if( a[i] != r ) return -1;
    return r;
}

int main(){
    int n;
    while( sc(n) && n ){

        for(int i = 0 ; i < n ; i++)
            sc(a[i]);
        
        int step = 0 , g;
        while( 1 ){
            g = val( n );
            if( g != -1 ) break;
            step++;
            for(int i = 0 ; i < n ; i++)
                b[(i+1)%n] = a[i]/2 , a[i] /= 2;
            
            for(int i = 0 ; i < n ; i++){
                a[i] += b[i];
                if(a[i]&1) a[i]++;
            }
        }
        
        printf("%d %d\n", step , g );
    }
    return 0;
}
