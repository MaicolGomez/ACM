#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<sstream>
using namespace std;

vector<bool> signo;
vector<int> coef;
vector<int> pot;
int test = 0,x;
bool ok,ok2;
string sol;
long long respuesta;
string f(int sig , int coe , int pote){
    string res = "";
        if( coe != 0 ){
            if(ok==0){
                if( sig == 0 ) res+="-";
                ok = 1;
            }
            else{
                 if( sig == 0 ) res+="-";
                else res+="+";
            }
                ostringstream on;
                on << coe;
                string cad = on.str();
                res+=cad;
                if(pote > 1 ){
                    res+="x";
                    if( pote > 2 ){
                        res += "^";
                        ostringstream on1;
                        on1 << (pote-1);
                        cad = on1.str();
                        res+=cad;
                    }
                }
        }
        return res;
}

string g(string res){
    string ret = "";
    for(int i = 0 ; i < res.length() ; i++){
        if( res[i] == 'x' ){
            ret+="(";
            ret+=sol;
            ret += ")";
        }
        else ret+=res[i];
    }
    if(ret.length()==0) return "0";
    return ret;
}

string h(int sig , int coe , int pote){
    if(coe==0) return "";
    string cad = "";
    int val = 1;
    if(sig==0) val*=-1;
    long long a = 1;
    for(int j = 1 ; j <= pote ; j++) a*=x;
    a *= (coe);
    a *= val;
    long long num = a;
    respuesta+=num;;
    ostringstream on;
    on << a;
    string p = on.str();
    if(ok2==0){
        //if(a<0) cad+="-";
        ok2=1;
    }
    else if(a>0) cad="+";
    cad+=p;
    return cad;
}

void solve(string ret){
    stringstream in(sol);
    in >> x;
    ok = 0,ok2=0;
    printf("POLYNOMIAL %d\n",++test);
    cout<<ret<<endl;
    vector<int>  s , c , p;
    for(int i = 0 ; i < signo.size() ; i++){
        s.push_back(signo[i]);
        c.push_back(coef[i]*pot[i]);
        p.push_back(pot[i]-1);
    }
    c.push_back(0);
    string res="";
    for(int i = 0 ; i < signo.size() ; i++){
        string p = f( s[i] , c[i] , pot[i] );
        res+=p;
    }
    if(res.length()==0) res = "0";
    cout<<res<<endl;
    cout<<g(res)<<endl;
    ok = 0;
    string rett="";
    for(int i = 0 ; i < signo.size() ; i++){
        string p = h( s[i] , c[i] , pot[i]-1 );
        rett+=p;
    }
    if(rett.size()==0) rett="0";
    cout<<rett<<endl;
    cout<<respuesta<<endl;
}

void doit(){
    respuesta = 0;
    signo.clear();
    coef.clear();
    pot.clear();
    cin >> sol;
    string s;
    cin >> s;
    if( s[0] != '-' && s[0] != '+' ) signo.push_back(1);
    for(int i = 0 ; i < s.length() ; i++){
        if( s[i] == '+' ) signo.push_back(1); //signo
        if( s[i] == '-' ) signo.push_back(0); //signo
        if( s[i] == 'x' ){  //coef
            if(i==0) coef.push_back(1); //coef
            else{ //coef
                if( '0' <= s[i-1] && s[i-1] <= '9' ) coef.push_back( s[i-1] - '0' ); //coef
                else coef.push_back(1); //coef
            } //coef
        } //coef
        if( s[i] == 'x' ){
            if( i == s.length() - 1 ) pot.push_back( 1 );
            else{
                if( s[i+1] == '^' ){
                    int num = 0;
                    for(int j = i + 2 ; j < s.length() ; j++){
                        if( !( '0' <= s[j] && s[j] <= '9') ) break;
                        num = num * 10 + s[j] - '0';
                    }
                    pot.push_back( num );
                }
                else pot.push_back(1);
            }
        }
    }
    if( pot.size() < signo.size() ) pot.push_back(0);
    if( coef.size() < signo.size() ) coef.push_back( s[s.length()-1] - '0' );
    solve(s);
}

int main(){
    int r;
    cin >> r;
    for(int i = 0 ; i < r; i++) doit();
}
