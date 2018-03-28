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
#define N 100000

vector<string> cur[8];

int main(){
    ios;
    int tc;
    int it;
    while( cin >> tc ){
            for(int i = 0 ; i < 6 ; i++)
                cur[i].clear();
                
            cur[2].pb( "C:" );
            cur[2].pb( "\\users" );
            cur[2].pb( "\\godle" );
            cur[3].pb( "D:" );
            cur[4].pb( "E:" );
            cur[5].pb( "F:" );
            it = 2;
            while( tc-- ){
                string a , b;
                cin >> a;
                if( a == "cd" ){
                    cin >> b;
                    if( b == ".." ){
                        if( cur[it].size() > 1 ){
                            //cout << cur[it].size() << endl;
                            cur[it].pop_back();
                            //cout << cur[it].size() << endl;
                        }
                    }
                    else{
                        string x = "";
                        x += '\\';
                        x += b;
                        cur[it].pb( x );
                    }
                }
                else{
                    int r = a[0] - 'A';
                    if( r < 2 or r > 5 ){}
                    else it = r; 
                }
                for(int i = 0 ; i < cur[it].size() ; i++)
                    cout << cur[it][i];
                cout << "\n";
            }
    }
    return 0;
}
