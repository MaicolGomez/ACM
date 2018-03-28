#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
#define eps 1e-7
#define inf 1<<30
#define ll long long
#define vi vector<int> 
#define vll vector<ll> 
#define pb(x) push_back(x)

int test = 0;
int main(){
    int a , b , c , d;
    while( scanf("%d%d%d%d",&a,&b,&c,&d) == 4 ){
        if( a == -1 && b == -1 && c == -1 && d == -1 ) break;
        if( a == b && b == c ){ printf("Case %d: the next triple peak occurs in %d days.\n",++test,21252 - d); continue; }
        for(int i = d+1 ;  ; i++){
            int x = (i-a)%23 , y = (i-b)%28 , z = (i-c)%33;
            if( x == 0 && y == 0 && z == 0 ){
                printf("Case %d: the next triple peak occurs in %d days.\n",++test,i-d);
                break;
            }
        }
    }
}
