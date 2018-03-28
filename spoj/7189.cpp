#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <climits>
#include <cctype>

#define ll long long
#define ull unsigned long long
#define all(v)  v.begin() , v.end()
#define rall(v)  v.rbegin() , v.rend()
#define FOR(it,A) for(typeof A.begin() it = A.begin(); it!=A.end(); it++)
#define REP(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define vull vector<ull>
#define vvi vector< vector<int> >
#define pii pair< int , int >
#define pll pair< ll , ll >
#define mp make_pair
#define fi first
#define se second
#define sc(x) scanf("%d",&x)
#define me(t,val) memset( t , val , sizeof(t) )
#define ones(x) __builtin_popcount(x)
#define test puts("test");
#define sync ios_base::sync_with_stdio(false);

#define N 40
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

string s[3];

string t[4] = { "espada" , "basto" , "copa" , "oro" };
int a[3];

int get(int x){
    if( x < 10 ) return x;
    return 0;
}

int main(){
    while( 1 ){
        int maxi = 0;
        for(int i = 0 ; i < 3 ; i++){
            cin >> a[i] >> s[i];
            maxi = max( maxi , get(a[i]) );
            if( a[i] == -1 ) return 0;
        }
        int cur = maxi;
        for(int i = 0 ; i < 3 ; i++)
            for(int j = i + 1 ; j < 3 ; j++)
                if( s[i] == s[j] ){
                    cur = max( cur , 20 + get(a[i]) + get(a[j]) );
                }
            
        int ans = 0;
        for(int i = 1 ; i <= 12 ; i++){
            if( i > 7 and i < 10 ) continue;
            for(int j = 0 ; j < 3 ; j++){ //pruebo carta j
                for(int k = 0 ; k < 4 ; k++){ //prueba valor k
                    int nv = i , mx = i;
                    string ns = t[k];
                    bool ok = 1;
                    for(int r = 0 ; r < 3 and ok ; r++)if( r != j ){
                        mx = max( mx , get(a[r]) );
                        if( nv == a[r] and ns == s[r] ) ok = 0;
                    }
                    if( !ok ) continue;
                    int punt = mx;
                    for(int p = 0 ; p < 3 ; p++)
                        for(int q = p + 1 ; q < 3 ; q++){
                            string aa = s[p] , b = s[q];
                            int tt = a[p] , gg = a[q];
                            if( p == j ) aa = ns , tt = nv;
                            if( q == j ) b = ns , gg = nv;
                            if( aa == b ){
                                punt = max( punt , 20 + get(tt) + get(gg) );
                            }
                        }
                    ans = max( ans , punt - cur );
                }
            }
        }
        printf("%d\n",ans);
    }
}

