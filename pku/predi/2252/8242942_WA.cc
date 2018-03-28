#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;

struct cosa{
    int x , y;
        cosa(int X , int Y){
            x = X;
            y = Y;    
        }
};

int cambia(string k ){
    int a = 0;
    for(int i = 0 ; i < k.length() ; i++){
        a = a*10 + (k[i] - 48);
    }
    return a;
}

cosa f( int a , int b , string s ){
    cosa q(0 , 0);
    int ct = 0;
    for(int i = a ; i <= b ; i++ ){
        if( s[i] == '(' ) ct++;
        if( s[i] == ')' ) ct--;
        if( ct == 0 && s[i] == '+' ){
            cosa r = f( a , i - 1 , s );    
            cosa w = f( i + 1 , b , s );
            q.x = r.x + w.x; q.y = r.y + w.y;
            return q;
        }
        if( ct == 0 && s[i] == '-' ){
            cosa r = f( a , i - 1 , s );    
            cosa w = f( i + 1 , b , s );
            q.x = r.x - w.x; q.y = r.y - w.y;
            return q;
        }
    }
    ct = 0;
    for(int i = a ; i <= b ; i++ ){
        if( s[i] == '(' ) ct++;
        if( s[i] == ')' ) ct--;
        if( ct == 0 && s[i] == '*' ){
            cosa r = f( a , i - 1 , s );    
            cosa w = f( i + 1 , b , s );
            q.x = r.x * w.y + r.y*w.x ; q.y = r.y * w.y;
            return q;
        }
    }
    if( s[a] == '(' ) return f( a + 1 , b - 1 , s );
    string m = "";
    for(int i = a ; i <= b ; i++) m += s[i];
    if( m == "x" ) return cosa( 1 , 0);
    int mm = cambia( m );
    return cosa( 0 , mm );
}

string  s2 ,s1;
int cont = 0;
void doit(){
    cont++;
    cosa p = f( 0 , s1.length() - 1 , s1 );
    cosa q = f( 0 , s2.length() - 1 , s2 );
    int cant = p.x - q.x;
    int res = q.y - p.y;
    printf("Equation #%d\n",cont);
    if( cant == res && cant == 0 ){ printf("Infinitely many solutions.\n\n"); return; }
    if( cant == 0 && res != 0 ){ printf("No solution.\n\n"); return; }
    double sol = 1.0*( res )/cant;
    printf("x = %.6lf\n",sol);
    puts("");
}

int main(){
    string ss;
    
    while( getline( cin , ss ) ){
        s2 = ""; s1 = "";
        for(int i = 0 ; i < ss.length() ; i++){
            if(ss[i] != '=') s1 += ss[i];
            if( ss[i] == '=' ){
                for(int j = i + 1 ; j < ss.length() ; j++){ s2 += ss[j];}
                break;
            }
        }
        doit();
    }
}
