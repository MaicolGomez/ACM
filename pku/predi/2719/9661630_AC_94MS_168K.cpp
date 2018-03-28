#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
#include<deque>
#include<map>
#include<string>
#include<map>
#include<sstream>
using namespace std;
#define inf (1<<30)
#define eps 1e-8
#define ll long long
char s[15];

int main(){
    while( gets( s ) ){
        if( s[0] == '0' ) break;
        int l = strlen( s );
        for(int i = 0 ; i < l ; i++) if( s[i] > '4' ) s[i]--;
        int res = 0;
        for(int i = 0 ; i < l ; i++) res = res * 9 + s[i] - '0';
        for(int i = 0 ; i < l ; i++) if( s[i] >= '4' ) s[i]++;
        for(int i = 0 ; i < l ; i++) printf( "%c",s[i] );
        printf(": %d\n",res);
    }
}