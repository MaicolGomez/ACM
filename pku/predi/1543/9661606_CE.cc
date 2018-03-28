#include<iostream>
#include<vector>
#include<cstdio>
#include<cmath>
using namespace std;
struct numeros{
    int sum , a , b  , c ;
        numeros( int Sum ,int A , int B , int C ){
            sum = Sum;
            a = A;
            b = B;
            c = C;
        }
};
bool operator<( numeros P , numeros Q ){
    if( P.sum != Q.sum ) return P.sum < Q.sum;
    if( P.a != Q.a ) return P.a < Q.a;
    if( P.b != Q.b ) return P.b < Q.b;
    return P.c < Q.c;
}
bool operator==(numeros P , numeros Q){
    if( P.sum == Q.sum ){
        return ( P.b == Q.c && Q.b == P.c );
    }
    return 0;
}
bool es[201*200*200];
bool son[201][201][201];
vector< numeros > v , v1 , res , res1;
void ordena(){
    for(int i  = 0 ; i < res1.size() ; i++){
        vector<int>k;
        k.push_back( res1[i].a );
        k.push_back( res1[i].b );
        k.push_back( res1[i].c );
        sort( k.begin() , k.end() );
        res1[i].a = k[0];
        res1[i].b = k[1];
        res1[i].c = k[2];
    }
}
void doit(){
    for(int i = 2 ; i < 201 ; i++){
        for(int j = 0 ; j < v.size() ; j++){
            if( i*i*i + v[j].sum > 200*200*200 ) break;
            if( es[ i*i*i + v[j].sum ] ){
                res.push_back( numeros( int( pow( 1.0*(i*i*i + v[j].sum + 1) , 1.0/3.0 ) ) , v[j].b , v[j].c , i ) );    
            }
        }
    }
    sort( res.begin() , res.end() );
    numeros r = res[0];
    res1.push_back( r );
    son[ r.a ][ r.b ][ r.c ] = 1;
    son[ r.a ][ r.c ][ r.b ] = 1;
    son[ r.b ][ r.a ][ r.c ] = 1;
    son[ r.b ][ r.c ][ r.a ] = 1;
    son[ r.c ][ r.a ][ r.b ] = 1;
    son[ r.c ][ r.b ][ r.a ] = 1;
    for(int i = 0 ; i < res.size() ; i++){
        if( res[i].sum == r.sum ){
            if( son[ res[i].a ][ res[i].b ][ res[i].c ] == 0 ){
                res1.push_back( res[i] );
                son[ res[i].a ][ res[i].b ][ res[i].c ] = 1;
                son[ res[i].a ][ res[i].c ][ res[i].b ] = 1;
                son[ res[i].b ][ res[i].a ][ res[i].c ] = 1;
                son[ res[i].b ][ res[i].c ][ res[i].a ] = 1;
                son[ res[i].c ][ res[i].a ][ res[i].b ] = 1;
                son[ res[i].c ][ res[i].b ][ res[i].a ] = 1;
            }
        }
        else{
            res1.push_back( res[i] );
            r = res[i];
            son[ res[i].a ][ res[i].b ][ res[i].c ] = 1;
            son[ res[i].a ][ res[i].c ][ res[i].b ] = 1;
            son[ res[i].b ][ res[i].a ][ res[i].c ] = 1;
            son[ res[i].b ][ res[i].c ][ res[i].a ] = 1;
            son[ res[i].c ][ res[i].a ][ res[i].b ] = 1;
            son[ res[i].c ][ res[i].b ][ res[i].a ] = 1;  
        }
    }
    ordena();
    //sort( res1.begin() , res1.end() );
    for(int i = 0 ; i < res1.size() ; i++){
        printf("Cube = %d, Triple = (%d,%d,%d)\n",res1[i].sum , res1[i].a , res1[i].b , res1[i].c );
    }
}
int main(){
    for(int i = 2 ; i < 201 ; i++){
        es[ i*i*i ] = 1;
        for(int j = i ; j < 201 ; j++){
            if( i * i * i + j * j * j > 200 * 200 * 201 ) break;
            v1.push_back( numeros( i*i*i + j*j*j , 0 , i , j  ) );
        }
    }
    sort( v1.begin() , v1.end() );
    numeros r = v1[0];
    v.push_back(r);
    for(int i = 0 ; i < v1.size() ; i++){
        if( !(r == v1[i]) ){
            v.push_back( v1[i] );
            r = v1[i];
        }
    }
    doit();
}