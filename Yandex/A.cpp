#include<bits/stdc++.h>
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
#define ios ios::sync_with_stdio(0)
#define N 8

int dx[8] = { 1 , 0 , -1 , -1 , -1 , 0 , 1 , 1 };
int dy[8] = { -1 , -1 , -1 , 0 , 1 , 1 , 1 , 0 };

pii get(string x){
    return mp( x[0] - 'a' , x[1] - '1' );
}

bool invalid[N][N] ;
int t[N][N];

void moveK(int x,int y){
    for(int i = 0 ; i < 8 ; i++){
        int u = x + dx[i] , v = y + dy[i];
        if( u >= 0 and u < N and v >= 0 and v < N )
            t[u][v] +=2 ;
    }
}

int xx[4] = { -1 , 1 , 0 , 0 };
int yy[4] = { 0 , 0 , 1 , -1 };

void moveR(int x,int y){
    for(int i = 0 ; i < 4 ; i++){
        for(int l = 1 ; l <= N ; l++){
            int u = x + l * xx[i] , v = y + l * yy[i];
            if( u < 0 or u >= N or v < 0 or v >= N or invalid[u][v] ) break;
            t[u][v]++;
        }
    }
}

int main(){
    string a , b , c;
    while( cin >> a >> b >> c ){
        pii A = get( a );
        pii B = get( b );
        pii C = get( c );
        me(invalid,0);
        me(t,0);
        invalid[A.fi][A.se] = 1;
        invalid[B.fi][B.se] = 1;
        moveK( A.fi , A.se );
        moveR( B.fi , B.se );
        int x = C.fi , y = C.se;
        if( t[x][y] >= 2 )
            cout << "Strange\n";
        else{
            int r = 0;
            for(int i = 0 ; i < 8 ; i++){
                int u = x + dx[i] , v = y + dy[i];
                if( u >= 0 and u < N and v >= 0 and v < N and t[u][v] == 0 ) 
                    r++;
            }
            //cout << x << " " << y << " --> " << t[x][y] << " " << r << endl;
            if( t[x][y] == 0 and r > 0 ) cout << "Normal\n";
            else if( t[x][y] and r > 0 ) cout << "Check\n";
            else if( t[x][y] == 0 and r == 0 ) cout << "Stalemate\n";
            else cout << "Checkmate\n";
        }
        
    }
    return 0;
}
