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
#define N 50000

bool used[N+5];
int A[3005];

int main(){
    for(int i = 1 ; i <= 3000 ; i++){
        int k = 2 , c = 0;
        while( used[k] ) k++;
        used[k] = 1;
        A[i] = k;
        //cout << "K: " << k << endl;
        for(int j = A[i] + 1 ; j <= N ; j++){
            if( used[j] ) continue;
            c++;
            if( c == k ){
                used[j] = 1;
                c = 0;
            }
        }
    }
    int n;
    while( sc(n) && n ){
        printf("%d\n",A[n]);
    }
    return 0;
}
