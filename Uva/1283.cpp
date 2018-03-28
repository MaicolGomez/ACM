#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
#include<deque>
#include<string>
#include<sstream>
using namespace std;
#define inf (1<<30)
#define eps 1e-8

vector<char> signo;
vector<int> num;
int  p , q , n , m;
bool have[1000];

void f(string s){
    memset(have,0,sizeof(have));
    signo.clear(); num.clear();
    p = 0 , q = 0;
    signo.push_back('+');
    for(int i = 0 ; i < s.length() ; i++){
        if( s[i] == '+' || s[i] == '-' ) signo.push_back(s[i]), s[i] = ' ';
    }
    int ini = 0;
    for(int i = 0 ; i < s.length() ; i++){
        if( s[i] == 'x' ){
            have[ini] = 1;
            if( i-1 < 0 || s[i-1] == ' ' ) s[i] = '1';
            else s[i] = ' ';
        }
        else if( s[i] == ' ' && i ) ini++;
    }
    stringstream in(s);
    int x;
    while( in >> x ) num.push_back(x);
    if( signo.size() < num.size() ){
        vector<char> aux(1,'+');
        for(int i = 0 ; i < signo.size() ; i++) aux.push_back(signo[i]);
        signo = aux;
    }
    /*for(int i = 0 ; i < num.size() ; i++) cout<<num[i]<<" ";
    cout<<endl;
    for(int i = 0 ; i < signo.size() ; i++) cout<<signo[i]<<" ";
    cout<<endl;
    for(int i = 0 ; i <= ini ; i++) cout<<have[i]<<" ";
    cout<<endl;*/
    //cout<<signo.size()<<" "<<num.size()<<" "<<ini<<endl;
    for(int i = 0 ; i < num.size() ; i++){
        if( have[i] ){
            if( signo[i] == '+' ) p+=num[i];
            else p-=num[i];
        }
        else{
            if( signo[i] == '+' ) q+=num[i];
            else q-=num[i];
        }
    }
}

void doit(){
    string s,a="",b="";
    cin >> s;
    signo.clear();
    num.clear();
    for(int i = 0 ; i < s.length() ; i++){
        if(s[i]!='=')a+=s[i];
        else{
            for(int j = i + 1 ; j < s.length() ; j++) b+=s[j];
            break;
        }
    }
    f(a);
    m = p , n = q;
    f(b);
    //cout<<m<<" "<<n<<" --  "<<p<<" "<<q<<endl;
    if( m == p && q == n ) puts("IDENTITY");
    else{
        if( m-p!=0 ) printf("%d\n", (q-n)/(m-p) );
        else puts("IMPOSSIBLE");
    }
}

int main(){
    int t;
    scanf("%d",&t);
    for(int i = 0 ; i < t ; i++) doit();
}

