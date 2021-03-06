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
#define N 130

int n , a[N][N][N] , t[N][N][N];

void update(int x,int y,int z,int c){
    while( x <= n ){
        int yy = y;
        while( yy <= n ){
            int zz = z;
            while( zz <= n ){
                t[x][yy][zz] += c;
                zz += zz&-zz;
            }
            yy += yy&-yy;
        }
        x += x&-x;
    }
}

int query(int x,int y ,int z){
    int ans = 0;
    while( x ){
        int yy = y;
        while( yy ){
            int zz = z;
            while( zz ){
                ans += t[x][yy][zz];
                zz -= zz&-zz;
            }
            yy -= yy&-yy;
        }
        x -= x&-x;
    }
    return ans;
}

int main(){
    sc(n);
    int m , x , y , z , c , x1 , y1 , z1, x2 , y2 , z2;
    while( sc(m) == 1 ){
        if( m == 3 ) break;
        else if( m == 1 ){
            scanf("%d%d%d%d",&x,&y,&z,&c); x++,y++,z++;
            if( a[x][y][z] + c <= 0 ) c = -a[x][y][z];
            update( x , y , z , c );
            a[x][y][z] = a[x][y][z] + c;
        }
        else{
            scanf("%d%d%d%d%d%d",&x1,&y1,&z1,&x2,&y2,&z2); x2++,y2++,z2++,x1++,y1++,z1++;
            int ans = query(x2,y2,z2) - query(x2,y2,z1-1) - query(x2,y1-1,z2) - query(x1-1,y2,z2)
                            + query(x1-1,y1-1,z2) + query(x1-1,y2,z1-1) + query(x2,y1-1,z1-1) - query(x1-1,y1-1,z1-1);
             printf("%d\n",ans);
        }
    }
    
    return 0;
}
