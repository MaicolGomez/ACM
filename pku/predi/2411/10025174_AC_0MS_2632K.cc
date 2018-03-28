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
#define inf (1<<30)
#define eps 1e-8
#define ll long long
#define vi vector<int> 
#define all(v) v.begin() , v.end()

ll t[1<<11][11][11] ;
int R , C;

ll f(int mask,int r, int c){
    if( r == R ) return mask == 0;
    ll &ret = t[mask][r][c];
    if( ret != -1 ) return ret;
    ret = 0;
    if( mask&(1<<c) ){
        if( c != C-1 ) return ret = f( mask^(1<<c) , r , c+1 );
        else return ret = f( mask^(1<<c) , r + 1 , 0 );
    }
    int a = c , b = c + 1;
    if( c + 2 <  C && !(mask&(1<<a)) && !(mask&(1<<b)) ) ret += f( mask , r , c + 2 ); //pone horizontal
    if( c + 2 == C && !(mask&(1<<a)) && !(mask&(1<<b)) ) ret += f( mask , r + 1 , 0 );
    if( c + 1 <  C && !(mask&(1<<c)) ) ret += f( mask|(1<<c) , r , c + 1 ); //pone vertical
    if( c + 1 == C && !(mask&(1<<c)) ) ret += f( mask|(1<<c) , r + 1 , 0 );
    return ret;
}

int main(){
    while( scanf("%d%d",&R,&C) == 2 && (R||C) ){
        if( C > R ) swap(R,C);
        if( R > 50 && C ){
            if( R%2 == 0 ) printf("1\n");
            else printf("0\n");
            continue;
        }
        for(int i = 0 ; i < 1<<C ; i++) for(int j = 0 ; j < R ; j++) for(int k = 0 ; k <= C ; k++) t[i][j][k] = -1;
        //memset( t , -1 , sizeof(t) );
        printf("%lld\n",f( 0 , 0 , 0) );
    }
}