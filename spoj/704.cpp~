#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
#include<deque>
#include<map>
#include<set>
#include<string>
#include<sstream>
using namespace std;
#define inf (1<<30)
#define eps 1e-8
#define ll long long
#define vi vector<int>
#define all(v) v.begin() , v.end()
#define sc(x) scanf("%d",&x)
#define me(t,val) memset( t , val , sizeof(t) )
#define fi first
#define se second
#define L(x) ((x<<1)+ 1)
#define R(x) L(x)+1
#define M(x,y) ((x+y)>>1)
#define N 1005

int b[N] , t[N*10][N];
char text[10*N] , s[N];

void kmp(){
    int l = strlen(s);
    int j = -1;
    b[0] = j;
    for(int i = 0 ; i < l ; i++){
        while( j >= 0 && s[j] != s[i] ) j = b[j];
        b[i+1] = ++j;
    }
}

int f(int x,int bor){
    if( bor == strlen(s) ) return inf;
    if( x == strlen(text) ) return 0;
    int &ret = t[x][bor];
    if( ret != -1 ) return ret;
    ret = 1 + f( x + 1 , bor );
    for(char i = text[x] ; i <= text[x] ; i++){
        int g = bor;
        while( g >= 0 && i != s[g] ) g = b[g];
        g++;
        ret = min( ret , f( x + 1 , g ) );
    }
    return ret;
}

int next[N][128];

int main(){
    while( scanf("%s",text) == 1 ){
        scanf("%s",s);
        kmp();
        
        int n = strlen(text) , l = strlen(s);
        for(int i = 0 ; i < l ; i++)for(char x = 'a' ; x <= 'z' ; x++){
            int g = i;
            while( g >= 0 && x != s[g] ) g = b[g];
            g++;
            next[i][x] = g;
        }
        
        for(int i = 0 ; i <= n ; i++) t[n][i] = 0 , t[i][l] = inf;
        t[n][l] = inf;
        for(int i = n - 1 ; i >= 0 ; i--){
            for(int j = 0 ; j < l ; j++){
                t[i][j] = 1 + t[i+1][j];
                int g = next[j][text[i]];
                t[i][j] = min( t[i][j] , t[i+1][g] );
            }
        }
        printf("%d\n",t[0][0]);
    }
}


