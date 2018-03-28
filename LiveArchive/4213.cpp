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
#define N 1005

int k , a , b , t[N][N] , m[N][N][2];
char A[N] , B[N];

int main(){
    while( sc(k) and k ){
        scanf("%s%s",A,B);
        a = strlen(A) , b = strlen(B);
        //cout << a << " " << b << endl;
        for(int i = 0 ; i < b + 1 ; i++)
            t[0][i] = 0 , m[0][i][0] = m[0][i][1] = 0;
        for(int i = 0 ; i < a + 1 ; i++)
            t[i][0] = 0 , m[i][0][0] = m[i][0][1] = 0;
        
        
        for(int i = 1 ; i < a + 1 ; i++)
            for(int j = 1 ; j < b + 1 ; j++){
                t[i][j] = 0;
                if( A[i-1] == B[j-1] ) t[i][j] = 1 + t[i-1][j-1];
            }

        for(int i = 1 ; i < a + 1 ; i++){
            for(int j = 1 ; j < b + 1 ; j++)
                for(int g = 0 ; g < 2 ; g++){
                    m[i][j][g] = max( m[i][j-1][0] , m[i-1][j][0] );
                    if( g ){
                        if( A[i-1] == B[j-1] ) m[i][j][g] = max( m[i][j][g] , 1 + m[i-1][j-1][1] );
                    }
                    else if( t[i][j] >= k ) m[i][j][g] =  max( m[i][j][g] , k + m[i - k][j-k][1] );
                }
            
        }
        printf("%d\n",m[a][b][0]);
        
    }
    return 0;
}
