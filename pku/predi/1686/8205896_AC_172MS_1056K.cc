#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<string>
using namespace std;
int n;
int tabla[128];
int v[26][10000];

int f( int a , int b , string &s , int posi ){
    int ct = 0;
    for(int i = b ; i >= a ; i-- ){
        if( s[i] == '(') ct++;
        if( s[i] == ')') ct--;
        if( s[i] == '+' && ct == 0 ) return f( a , i - 1 , s , posi ) + f( i + 1 , b , s , posi  );
        if( s[i] == '-' && ct == 0 ) return f( a , i - 1 , s , posi ) - f( i + 1 , b , s , posi  );
        if( ct == 0 && s[i] == '*' ) return f( a , i - 1 , s , posi ) * f( i + 1 , b , s , posi );
    }
    if( s[a] == '(' ) return f( a + 1 , b - 1 , s , posi );
    if( isdigit(s[a]) ) return s[a] - '0';
    int x = tabla[ s[a] - 'a'];
    return v[x][posi];
}

string arregla( string ss ){
    string aux = "";
    for( int i = 0 ; i < ss.length() ; i++ ) if( ss[i] != ' ' ) aux += ss[i];
    return aux;
}

void doit(){
    string s , s1;
    getline( cin , s );
    getline( cin , s1 );
    s = arregla( s );
    s1 = arregla( s1 );
    int tot = 0 ;
        for(int i = 0 ; i < 128 ; i++) tabla[i] = -1;
        for(int i = 0 ; i < s.length() ; i++){
            if( s[i] >= 'a' && s[i] <= 'z' && (tabla[s[i] - 'a'] == -1) ){
                tabla[ s[i] - 'a' ] = tot++;
            }
        }
        for(int i = 0 ; i < s1.length() ; i++){
            if( s1[i] >= 'a' && s1[i] <= 'z' && (tabla[ s1[i] - 'a' ] == -1) ){
                tabla[ s1[i] - 'a' ] = tot++;
            }
        }
    for(int i = 0 ; i <= tot ; i++){
        for( int j = 0 ; j < 10000 ; j++){
            v[i][j] = rand()%100000;
        }
    }
    bool ok = 1;
    for(int i = 0 ; i < 10000 ; i++){
        int p = f( 0 , s.length() - 1  , s , i );
        int r = f( 0 , s1.length() - 1 , s1 , i);
        if( p !=r ){
            cout<<"NO"<<endl;
            ok = 0;
            break;
        }
    }
    if( ok ) cout<<"YES"<<endl;
}

int main(){
    scanf("%d",&n);
    string k;
    getline( cin , k );
    for(int i = 0 ; i < n ; i++){
        doit();
    }
}
