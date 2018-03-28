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
int n , t , b[N];
char s[N];

void process(){
    int j = -1;
    b[0] = -1;
    for(int i = 0 ; i < n ; i++){
        while( j >= 0 && s[i] != s[j] ) j = b[j];
        j++;
        b[i+1] = j;
    }
}

int main(){
    int test = 0;
    while(scanf("%d",&n) == 1 && n ){
        scanf("%s",s);
        process();
        printf("Test case #%d\n",++test);
        for(int i = 1 ; i <= n ; i++){
            if( i%( i - b[i] ) == 0 && i /( i - b[i] ) > 1 ){
                printf("%d %d\n", i , i/(i-b[i]) );
            }
        }
        printf("\n");
    }
}
