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
#define eps 1e-6
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
#define N 100
#define ALPH_SIZE 52
  
using namespace std;
int n , t[1<<12][N];

int f(int mask,int k){
    if( mask == 0 )
        return (k == 0);
    int &ret = t[mask][k];
    if( ret != -1 ) return ret;
    /*for(int i = 0 ; i < n ; i++)if( mask&(1<<i) )
        cout << i + 1 << " ";
    cout << "- " << k << endl;*/
    ret = 0;
    int ct = 0;
    for(int i = 0 ; i < n ; i++){
        if( mask&(1<<i) && k - ct >= 0 ) ret += f( mask^(1<<i) , k - ct );
        else ct++;
    }
    return ret;
}

int main(){
    int tc , k;
    me(t,-1);
    sc(tc);
    while( tc-- ){
        sc(n),sc(k);
        printf("%d\n",f( (1<<n)-1 ,k));
    }
}


