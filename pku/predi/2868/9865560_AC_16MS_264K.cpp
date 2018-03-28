#include<iostream>
#include<cmath>
#include<cctype>
#include<deque>
#include<cstdio>
#include<sstream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int n , q;
int b[27] , num;
int bl , filbl , colfil , colcol , tot;

string doit(int n , int base){
    num = 0;
    while( n > 0){        
        int m  = n % base;        
        if(m == 0){
            b[num] = base;
            n /= base;
            n--;
        }
        else{
            b[num] = m;
            n /= base ;            
        }
        num++;      
    } 
   string s1;
   for(int i = num - 1  ; i >= 0 ; i--){ 
        char k = 'A' + b[i] - 1;
        s1 += k; 
    }  
    return s1;
}

void calcula(int a , int base){
    int bl;
    double p , aco = 0.0 , res;
    for(int i = 1 ; i < 30 ; i++){
        p = pow( 1.0 * base , i * 1.0 ) * i;
        res = a - aco;
        aco += p;
        if( int(aco) >= a ){
            bl = i; break;    
        }
    }
    filbl = int(res)/(bl*base);
    if( int(res)%(bl*base) != 0) filbl++;
    int k = (int(res) - 1) % (bl * base) + 1;
    colfil = ( k - 1 ) / bl + 1;
    int r = ( filbl - 1)* bl * base + (colfil - 1 ) * bl;
    colcol = int(res) - r;
    tot = 0;
    for(int i = 1 ; i < bl ; i++){
        tot += int( pow( 1.0 * base , 1.0 * i ) );
    }   
    tot += ( (filbl - 1) * base + colfil );
}

int main(){
    while( scanf("%d%d", &n , &q) ){
        if(n == 0 && q == 0) break;
        string s;
        vector <string> v;
        for(int i = 0 ; i < n ; i++){
            cin >> s;
            v.push_back( s ); 
        }
        string x;
        int a;
        if( n != 1){
            for( int i = 0 ; i < q ; i++){
                scanf("%d", &a );
                calcula(a , n);
                x = doit( tot , n  );
                char t;;
                t = x[ colcol - 1 ];
                printf("%s\n",v[ t - 'A'].c_str() );
            }
        }
        else{
            for(int i = 0 ; i < q ; i++){
                scanf("%d", &a );
                cout<<v[0]<<endl;  
            }  
        }
        printf("\n");
    }
}