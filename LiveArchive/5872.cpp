#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <climits>
#include <cctype>
 
#define IT 1
#define ALP 26
#define ll long long
#define MOD 1000007
using namespace std;
 
int tc , ns ,nt ;
string cad ,t ,dummy;
long long val[ALP];
 
void shuff()
{    
        for( int i = 0 ; i < ALP ; ++i )
                val[i] = rand()%7 + 1;
                
}
//a*2-(a+c)+((a+c+e)*2)
//3*a+c+(2*e)
long long f( string &s , int a , int b, char ope){
    if( b < a ) return 0;
    int ct = 0;
    for(int i = b ; i >= a ; i--){
        if( s[i] == '(' ) ct++;
        if( s[i] == ')' ) ct--;
        if( s[i] == '+' && ct == 0 ){
            return (f( s , a , i - 1 , ' ' ) + f( s , i + 1 , b , ' ' ))%MOD;
        }
        if( s[i] == '-' && ct == 0 )
            return (f( s , a , i - 1 , ' ' ) - f( s , i + 1 , b , '-' ))%MOD;
        
    }
    ct = 0;
    for(int i = b ; i >= a ; i--){
        if( s[i] == '(' ) ct++;
        if( s[i] == ')' ) ct--;
        if( s[i] == '*' && ct == 0 )
            return (f( s , a , i - 1 , ' ' ) * f( s , i+1 , b , ' ' ))%MOD;
        
    }
    if( s[a] == '(' ) return f( s , a+1 , b-1 , ope );
    if( s[a] >= '0' && s[a] <= '9' ) return (s[a] - '0');
    return val[ toupper(s[a]) - 'A' ];
}

string g(string x){
    string ans = "";
    for(int i = 0 ; i < x.size() ; i++)
        if( x[i] != ' ' ) ans += x[i];
    return ans;
}

int main()
{
        cin >> tc;
        getline( cin , dummy );
        while( tc-- )
        {
                getline( cin , cad );
                getline( cin , t );
                cad = g(cad);
                t = g(t);
                ns = cad.size();
                nt = t.size();
                int cnt = 0;
                for( int k = 0 ; k < IT ; ++k )
                {       
                        shuff();
                        ll nums = f(cad , 0 , ns-1 , ' ' );
                        //puts("***");            
                        ll numf = f(t , 0 , nt-1 , ' ' );
                        //puts("***");
                        /*for( int i = 0 ; i < 5 ; ++i )
                            cout << char('A' + i) << " " << val[i] << " ";
                        puts("");
                        cout << nums << " " << numf << endl;*/
                        if( nums == numf )
                                cnt++;
                }
                //cout << cnt << endl;
                if( cnt == IT )
                        puts( "YES" );
                else    puts( "NO" );
        }
        
}
