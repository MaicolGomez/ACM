#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
#include<deque>
#include<map>
#include<string>
#include<sstream>
using namespace std;
#define pi (2.0*acos(0.0))
#define inf (1<<30)
#define me( arr , val ) memset( arr , val , sizeof(arr) );
#define eps 1e-8
#define ll long long
#define vi vector<int> 
#define all(v) v.begin() , v.end()
#define N 200

int  p[ 200005];
bool vis[ 200005 ];
void makeset(int x){
    for(int i = 0 ; i < 2*x ; i++) p[i] = i ;
}

int FIND(int x){
    if( p[x] != x )
        p[x] = FIND( p[x] );
    return p[x];
}

void UNION(int x, int y){
    x = FIND(x);
    y = FIND(y);
    p[x] = y;
}

int n , m;

int other(int x){
    return x + n;
}

void doit(){
    scanf("%d%d",&n,&m);
    makeset(n);
    for(int i = 0 ; i < n ; i++) vis[i] = 0;
    char l;
    int x, y;
    char r[100];
    gets( r );
    for(int i = 0 ; i < m ; i++){
        //scanf("%c%d%d",&l,&x,&y);
        gets(r);
        //string s = string(r);
        //stringstream in(s);
        //in >> l >> x >> y;
        sscanf(r,"%c %d %d",&l,&x,&y);
        //cout << l << " " << x << " " << y << endl;
        if( l == 'A' ){
            if( vis[x] && vis[y] ){
                if( FIND(x) == FIND(y) ) puts("In the same gang.");
                else puts("In different gangs.");
            }
            else puts("Not sure yet.");
        }
        else{
            vis[x] = vis[y] = 1;
            UNION( x , other(y) ); UNION( y , other(x) );
        }
    }
}

int main(){
    int t;
    scanf("%d",&t);
    for(int i = 0 ; i < t ; i++) doit();
}