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

struct team{
    int x , d[2] , prefer , diff;
    team(){}
    team(int X,int da,int db){
        x = X, d[0] = da , d[1] = db;
        diff = abs( da - db );
        prefer = 1;
        if( da < db ) prefer = 0;
    }
};


bool operator<(team A,team B){
    return A.diff < B.diff;
}

int d[N][2];

int main(){
    int n , A , B;
    while( scanf("%d%d%d",&n,&A,&B) == 3 and n > 0 ){
        team T[n];
        int k[n] , da , db;
        for(int i = 0 ; i < n ; i++){
            scanf("%d%d%d",&k[i],&da,&db);
            T[i] = team( k[i] , da , db );
        }
        sort( T , T + n );
        int a[2] = { 0 , 0 };
        int ans = 0;
        for(int i = 0; i < n ; i++){
            int p = T[i].prefer;
            ans += T[i].x * T[i].d[p];
            a[p] += T[i].x;
        }
        //cout << a[0] << " " << a[1] << endl;
        if( a[0] <= A and a[1] <= B ) printf("%d\n",ans);
        else{
            int p = 0;
            int q = 1 - p;
            if( a[1] > B ) swap( p , q );
            int need = a[p] - ((p)?B:A);
            for(int i = 0 ; i < n ; i++)
                if( T[i].prefer == p and need ){
                    if( T[i].x <= need ){
                        ans += (T[i].d[q] - T[i].d[p]) * T[i].x;
                        need -= T[i].x;
                    }
                    else{
                        ans += (T[i].d[q] - T[i].d[p]) * need;
                        need = 0;
                    }
                }
            printf("%d\n",ans);
        }
    }
    return 0;
}
