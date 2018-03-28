#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int n;
int a[27];
int caso = 0;
int main(){
    while( scanf("%d",&n) ){
        if( n == 0 ) break;
        caso++;
        string s , s1;
        int pot = 1;
        for(int i = 1 ; i <= n ; i++){
            cin >> s;
            pot *=2;
            a[ i ] = s[1] - '0'  ;
        }
        cin >> s;
        int c;
        scanf("%d",&c);
        cout<<"S-Tree #"<<caso<<":"<<endl;
        for(int i = 0 ; i < c ; i++){
            cin >> s1;
            string res = "";
            for(int j = 1 ; j <= s1.length() ; j++){
                res += s1[ a[ j ] - 1 ];
            }
            int suma = 1;
            for(int j = 0 ; j < res.length(); j++ ){
                if( res[j] == '1' ) suma = suma*2+1;
                else suma *= 2;
            }
            cout<<s[ suma - pot ];
        }
        cout<<endl<<endl;
    }
}
