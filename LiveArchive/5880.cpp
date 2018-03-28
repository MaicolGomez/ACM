#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
#include<set>
#include<deque>
#include<map>
#include<string>
#include<stack>
#include<sstream>
using namespace std;
#define pii (2.0*acos(0.0))
#define inf (1<<30)
#define eps 1e-8
#define ll long long
#define vi vector<int> 
#define all(v) v.begin() , v.end()
#define me(a,val) memset( a , val ,sizeof(a) )
#define pb(x) push_back(x)
#define N 1000005
char s[N] , t[N/100] ;

int main(){
    while( scanf("%s",t) ){
        if( t[0] == '0' ) break;
        scanf("%s",s);
        int l = strlen(t);
        for(int i = 0 ; i < strlen(s) ; i++){
            int x = t[i%l] - 'A' + 1;
            printf("%c", (s[i] + x > 'Z' )?( (s[i] + x - 'Z' + 'A'-1) ):( s[i]+x ) );
        }
        printf("\n");
    }
}
