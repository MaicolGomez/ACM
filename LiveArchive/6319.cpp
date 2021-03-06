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
#define eps 1e-7
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
#define M(x,y) ((x+y)>>1)
#define fi first
#define se second
#define MOD 1000000007
#define ios ios::sync_with_stdio(0)
#define N 40100
#define LMAX 1000

string s[N];
int next , d[N] , last;
char R[1000005];

void insert(){
    string r;
    int pos;
    scanf("%s%d",R,&pos);
    //cout << pos << endl;
    r = string(R);
    int voy = 0 , estoy = 0 , b = 0 , inicio;
    while( 1 ){
        if( voy + s[estoy].size() < pos ){
            voy += s[estoy].size();
            estoy = d[estoy];
        }
        else{
            inicio = pos - voy;
            b = estoy;
            break;
        }
    }
    //if( pos == 47057 ) cout << r << "\n";
    r += s[b].substr(inicio);
    s[b] = s[b].substr( 0 , inicio );
    //if( pos == 47057 ) cout << r << " --\n";
    
    int e = 0;
    int size = r.size();
    int go = d[b];
    while( s[b].size() != LMAX ){
        s[b] += r[e++];
        if( e == size ) return;
    }
    r = r.substr( e );
    //if( pos == 47057 ) cout << r << " " << s[go].size() << "\n";
    if( s[go].size() != LMAX ){
        int x = LMAX - s[go].size();
        if( x > 0 ){
            if( x <= r.size() ){
                s[go] = r.substr( r.size() - x ) + s[go];
                r = r.substr( 0 , r.size() - x );
            }
            else{
                s[go] = r + s[go];
                r = "";
            }
        }
    }
    size = r.size();
    e = 0;
    if( size == 0 ) return;
    
    d[b] = next;
    while( 1 ){
        d[next] = next + 1;
        while( s[next].size() != LMAX ){
            s[next] += r[e++];
            if( e == size ) break;
        }
        if( e == size ){
            d[next] = go;
            next++;
            return;
        }
        next++;
    }
    
}

void print(){
    int a , b;
    scanf("%d%d",&a,&b);
    //cout << a << " " << b << endl;
    //return;
    int voy = 0 , estoy = 0 , block = 0 , inicio;
    while( 1 ){
        if( voy + s[estoy].size() < a ){
            voy += s[estoy].size();
            estoy = d[estoy];
        }
        else{
            inicio = a - voy;
            block = estoy;
            break;
        }
    }
    int size = b - a + 1 , l = 0;
    while( l < size ){
        //c/out << block << " " << s[block].size() << endl;
        for(int i = inicio ; i < s[block].size() and l < size ; i++){
            printf("%c",s[block][i]);
            l++;
        }
        if( l == size ) return;
        block = d[block];
        inicio = 0;
    }
}

char CAD[1000005];

int main(){
    int tc = 1;
    string cad;
    sc(tc);
    while( tc-- ){
        for(int i = 0 ; i < N ; i++)
            s[i] = "" , d[i] = i + 1;
        scanf("%s",CAD);
        cad = string(CAD);
        int size = cad.size();
        last = 0 , next = 0;
        for(int i = 0 ; i < size ; i += LMAX){
            if( size - i >= LMAX ){
                d[last] = last + 1;
                s[last] = cad.substr( i , LMAX );
                if( i + LMAX >= size ) d[last] = 20000;
                last++;
            }
            else{
                s[last] = cad.substr( i );
                d[last] = 20000;
            }
        }
        next = last + 1;
        //cout << d[0] << " " << last << endl;
        //cout << next << endl;
        char tipo[10];
        int it = 0;
        while( 1 ){
            scanf("%s",tipo);
            if( tipo[0] == 'E' )
                break;
            else if( tipo[0] == 'I' )
                insert();
            else{
                print();
                printf("\n");
            }
        }
    }   
}
