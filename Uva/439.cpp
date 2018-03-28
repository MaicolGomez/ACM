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
#define N 10

pii f(string s){
    return mp( s[1] - '0' - 1,  s[0] - 'a' );
}

int dx[8] = { -2 , -1 , 1 , 2 , 2 , 1 , -1 , -2 };
int dy[8] = { -1 , -2 , -2 , -1 , 1 , 2 , 2 , 1 };



int main(){
    string s , t;
    while( cin >> s >> t ){
        pii S = f(s) , T = f(t);
        queue< pii > Q;
        Q.push( S );
        int d[N][N] , pa[N][N];
        for(int i = 0 ; i < N ; i++)
            for(int j = 0 ; j < N ; j++)
                d[i][j] = inf;
        d[S.fi][S.se] = 0;
        pa[S.fi][S.se] = -1;
        //cout << S.fi << " " << S.se << endl;
        //cout << T.fi << " " << T.se << endl;
        while( !Q.empty() ){
            pii q = Q.front(); Q.pop();
            int x = q.fi , y = q.se;
            //cout << x << " " << y << endl;
            for(int i = 0 ; i < 8 ; i++){
                int u = x + dx[i] , v = y + dy[i];
                if( u >= 0 && u < 8 && v >= 0 && v < 8 && d[u][v] == inf ){
                    d[u][v] = d[x][y] + 1;
                    pa[u][v] = i;
                    if( u == T.fi && T.se == v ) goto xx;
                    Q.push( mp(u,v) );
                }
            }
        }
        xx:
        cout << "To get from " << s << " to " << t <<" takes " << d[T.fi][T.se] << " knight moves." << endl;
    }
    return 0;
}
