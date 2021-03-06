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
#define N 100001

int main(){
    int n;
    while( sc(n) == 1 ){
        vector<int> v( 10 , 0 );
        if( n == 0 ){
            cout << "10\n";
            continue;
        }
        if( n == 1 ){
            cout << "1\n";
            continue;
        }
        for(int i = 9 ; i >= 2 ; i--){
            while( n > 1 and n%i == 0 ){
                v[i]++;
                n/=i;
            }
        }
        if( n > 1 ) printf("-1\n");
        else{
            for(int i = 2 ; i <= 9 ; i++)
                for(int j = 0 ; j < v[i] ; j++)
                    printf("%d",i);
            cout << "\n";
        }
    }
    return 0;
}

