#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
#include<deque>
#include<set>
#include<map>
#include<string>
#include<map>
#include<sstream>
using namespace std;
#define inf (1<<30)
#define eps 1e-5
#define ll long long
#define all(v)  v.begin() , v.end()
#define vi vector<int> 

string suma(string a , string b){
    reverse(a.begin() , a.end());
    reverse(b.begin() , b.end());
    int r = a.length();
    int x = b.length();
    if(r < x)for(int i = r ; i < x ; i++) a += "0";
    else if(r > x)for(int i = x ; i < r ; i++) b += "0";
    int lleva = 0;
    string res = "";
    for(int i = 0 ; i < a.length() ; i++){
        int p = lleva + a[i] - '0' + b[i] - '0';
        lleva = p/10;
        res += char(p%10+'0');
    }
    if(lleva) res += "1";
    reverse( res.begin() , res.end() );
    return res;
}

string F[255];

int main(){
    for(int i = 0 ; i <= 250 ; i++) F[i] = "0";
    F[0] = "1";
    F[1] = "1";
    for(int i = 2 ; i <= 250 ; i++) F[i] = suma( F[i-1] , suma( F[i-2] , F[i-2] ) );
    int n;
    while( scanf("%d",&n) == 1 ){
        //printf("%s\n",F[n]_str() );
        cout << F[n] << endl;
    }
}