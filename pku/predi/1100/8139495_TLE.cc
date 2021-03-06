#include<iostream>
#include<cstdio>
#include<vector>
#include<sstream>
#include<string>
using namespace std;
string s , res;
int sol;
string respuesta;
vector < vector<int> > vv;
int espacios;

string arregla(string res){
    vector <string> v;
    string ret = "";
    istringstream in(res);
    string r;
    espacios = 0;
    while( in >> r ){
        v.push_back( r );
    }
    ret += v[0];
    for(int i = 1 ; i < v.size() - 1 ; i++){
        if( v[i-1][ v[i-1].length() - 1 ] != '(' && v[i][ 0 ] != ')' ){ ret += " "; espacios++; }
        ret += v[i];
    }
    if( v.size() > 1 ){
        if( v[ v.size() - 1 ] != ")"){ ret+= " ";  espacios++;   }
    }
    if( v.size() > 1 ) ret += v[v.size() - 1];
    return ret;
}

int parsea( string a ){
    istringstream in(a);
    int t;
    in >> t;
    return t;
}

int f(int ini , int fin){
    int cont1 = 0 , cont2 = 0;
    for(int i = fin ; i >= ini ; i-- ){
        if( s[i] == '(' ) cont1++;
        if( s[i] == ')' ) cont2++;
        if( s[i] == '+' && cont1 == cont2 ) return f(ini , i - 1 ) + f(i+1 , fin);
        if( s[i] == '-' && cont1 == cont2 ) return f(ini , i - 1 ) - f(i+1 , fin);
        if( s[i] == '*' && cont1 == cont2 ) return f(ini , i - 1 ) * f(i+1 , fin);
    }
    if( s[ini] == '(' ) return f(ini+1,fin-1);
    string ret = "";
    ret = s.substr( ini , fin - ini + 1 );
    int k = parsea( ret );
    return k;
}

bool ok = 0;

void llama(vector <char> &v ){
    string copia = res;
    int cont = 0;
    for(int i = 0 ; i < copia.length() ; i++ ){
        if( copia[i] == ' ' ){ copia[i] = v[cont]; cont++;  }
    }
    s = copia;
    int pp = f( 0 , s.length() - 1 );
    //cout<<s<<endl;
    //cout<<sol<<" "<<pp<<endl;
    if( pp == sol ){ ok = 1; cout<<sol<<"="<<s<<endl;}
}

void genera( vector <char> &v ){
    if( v.size() == espacios ){
        llama( v );
        return;
    }
    if( ok == 1 ) return;
    for(int i = 0 ; i < 3 ; i++){
        if( ok == 1 ) return;
        if(i == 0 ){
            v.push_back('+');
            genera(v);
        }
        if( i==1 ){
            v.push_back('-');
            genera(v);
        }
        if(i==2 ){
            v.push_back('*');
            genera(v);
        }
        v.pop_back();
    }
}
int tot = 0;
int main(){
    while( getline( cin , s ) ){
        if( s == "0" ) break;
        res = "";
        ok = 0;
        vv.clear();
        for(int i = 0 ; i < s.length() ; i++ ){
            if( s[i] == '=' ){
                string par = "";
                for(int j = 0; j < i  ; j++ ){
                    par += s[j];    
                }
                sol = parsea( par );
                for(int j = i + 1 ; j < s.length() ; j++ ){
                    res += s[j];    
                }
                break;
            }
        }
        tot++;
        cout<<"Equation #"<<tot<<":"<<"\n";
        res = arregla(res);
        vector <char> v;
        genera( v );
        if( !ok ) cout<<"Impossible"<<endl;
        cout<<"\n";
    }
}
