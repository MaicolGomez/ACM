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
#define N 101

char s[10][2][N] , t[N*5];

int main(){
    while( gets(s[0][0]) ){
        int n;
        sscanf(s[0][0],"%d",&n);
        if( !n ) break;
        for(int i = 0 ;  i < n ; i++){
            gets(s[i][0]);
            gets(s[i][1]);
        }
        gets(t);
        string text = "";
        for(int i = 0 ; i < strlen(t) ; i++)
            text += t[i];
        for(int p = 0 ; p < n ; p++){
            int len = strlen(s[p][0]);
            int tam = strlen(s[p][1]);
            while( 1 ){
                string ns = "";
                bool find = 0;
                for(int i = 0 ; i < text.size() ; ){
                    if( !find and i + len <= text.size() ){
                        bool same = 1;
                        for(int j = 0 ; same and j < len ; j++)
                            if( s[p][0][j] != text[i+j] ) same = 0;
                        
                        if( same ){
                            for(int j = 0 ; j < tam ; j++)
                                ns += s[p][1][j];
                                
                            i += len,find = 1;
                        }
                        else ns += text[i++];
                    }
                    else ns += text[i++];
                }
                //cout << text << " " << ns << " - " << s[p][0] << " " << find << endl;
                text = ns;
                if( !find ) break;
            }
        }
        printf("%s\n",text.c_str());
    }
    return 0;
}
