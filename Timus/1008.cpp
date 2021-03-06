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
#define fi first
#define se second
#define MOD 10009
#define N 15

int m[N][N];
bool used[N][N];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
string S = "RTLB";

void f(int n){
    pii A[n];
    for(int i = 0 ; i < n ; i++)
        sc(A[i].fi) , sc(A[i].se) , m[A[i].fi][A[i].se] = 1;
    
    printf("%d %d\n",A[0].fi,A[0].se);
    queue<pii> Q;
    Q.push( A[0] );
    used[A[0].fi][A[0].se] = 1;
    while( !Q.empty() ){
        pii q = Q.front(); Q.pop();
        string ans = "";
        for(int i = 0 ; i < 4 ; i++){
            int u = q.fi + dx[i] , v = q.se + dy[i];
            if( !used[u][v] && m[u][v] ){
                used[u][v] = 1;
                ans += S[i];
                Q.push( mp(u,v) );
            }
        }
        if( Q.size() > 0 ) ans += ',';
        else ans += '.';
        printf("%s\n",ans.c_str());
    }
}

void g(int x,int y){
    map<char,int> M;
    M['R'] = 0 , M['T'] = 1 , M['L'] = 2 , M['B'] = 3;
    int n = 0;
    string s[105] , t;
    while( cin >> t ){
        s[n++] = t;
    }
    int r = 0;
    pii A[105];
    A[r++] = mp( x , y );
    queue<pii> Q;
    Q.push( mp(x,y) );
    int h = 0;
    while( !Q.empty() ){
        pii q = Q.front(); Q.pop();
        for(int i = 0 ; i < s[h].size() - 1 ; i++){
            int ind = M[s[h][i]];
            int u = q.fi + dx[ind] , v = q.se + dy[ind];
            A[r++] = mp( u , v);
            Q.push( mp(u,v) );
        }
        h++;
    }
    sort( A , A + r );
    printf("%d\n",r);
    for(int i = 0 ; i < r ; i++)
        printf("%d %d\n",A[i].fi,A[i].se);
}

int main(){
    string s;
    getline( cin , s );
        bool space = 0;
        for(int i = 0 ; i < s.size() ; i++) space |= (s[i] == ' ');
        stringstream in(s);
        int n , x , y;
        if( !space ){
            in >> n;
            f( n );
        }
        else{
            in >> x >> y;
            g( x , y );
        }
    
    return 0;
}
