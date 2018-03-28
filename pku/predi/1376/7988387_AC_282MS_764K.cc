#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
#define inf 100000000

struct nodo{
    int x , y , d , dis;
        nodo( int X , int Y , int D ,int Dis){
            x = X;
            y = Y;
            d = D;
            dis = Dis;
        }
};

bool operator <(nodo A , nodo B){
    return A.dis > B.dis;        
}

int M , N , C , D;
char mat[52][52];
int dx[4]={-1,0,1, 0};
int dy[4]={ 0,1,0,-1};

bool entra(int x , int y , int dir , int a , int b ){
    if( x > N - 1 || x < 1 || y > M - 1 || y < 1 ) return false;
    if( mat[x][y] == '*' ) return false;
    while(true){
        a += dx[ dir ] , b+= dy[ dir ];
        if( mat[a][b] == '*' ) return false;
        if( a == x ) return true;   
    }
}

int f( nodo source ){
    int dis[51][51][4];
    for(int i = 0 ; i <= N ; i++)
        for(int j = 0; j <= M ; j++)
            for(int k = 0 ; k < 4 ; k++)
                dis[i][j][k] = inf;   
            
    priority_queue <nodo> Q;
    Q.push( source );
    dis[ source.x ][ source.y ][ source.d ] = 0;
    int temp = inf;
    while( !Q.empty() ){
        nodo q = Q.top();
        if( q.x == C && q.y == D ) if( q.dis < temp ) temp = q.dis; 
        Q.pop();
        for(int i = 0 ; i < 4 ; i++){
            for(int j = 1 ; j <= 3 ; j++){
                int x1 = q.x + dx[i] * j , y1 = q.y + dy[i] * j;
                if( entra( x1 , y1 , i , q.x , q.y ) ){
                    int m;
                    m = abs( q.d - i);
                    if( m == 3) m = 1;
                    m = q.dis + m + 1;
                    if( m < dis[x1][y1][i] ){
                        //cout<<q.x<<" "<<q.y<<" "<<q.d<<" "<<q.dis<<"------>> ";cout<<x1<<" "<<y1<<" "<<i<<" "<<m<<" "<<mat[x1][y1]<<endl;
                        dis[x1][y1][i] = m;
                        Q.push( nodo( x1 , y1 , i , m ) );    
                    }
                }
            }
        }
    }
    if(temp == inf) return -1;
    else return temp;
}

void doit(){
    int a , b , p;
    string s;
    for(int i = 0 ; i <= N ; i++)
        for(int j = 0 ; j <= M ; j++)
            mat[i][j] = '.';

    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            cin >> p;
            if( p == 1 ){
                mat[i][j] = '*';
                mat[i][j+1] = '*';
                mat[i+1][j] = '*';
                mat[i+1][j+1] = '*';
            }
        }
    }
    scanf("%d%d%d%d",&a,&b,&C,&D);
    cin >> s;
    int r;
    if( s == "east" ) r = 1;
    if( s == "west" ) r = 3;
    if( s == "south") r = 2;
    if( s == "north") r = 0;
    printf("%d\n",f( nodo (a , b , r , 0 ) ) );
}

int main(){
    while( scanf("%d%d",&N,&M) ){
        if( N == 0 && M == 0 ) break;
        doit();
    } 
}
