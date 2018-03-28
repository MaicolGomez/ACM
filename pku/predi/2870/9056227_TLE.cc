#include<vector>
#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
#define inf 50
int R,C,need[7][7],solution,pintado[7][7],total;
bool puesto[7][7];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

bool valid(int fila){
    for(int i = 0 ; i < C; i++){
        if(need[fila][i]>=0){
            int cont = 0;
            for(int j = 0 ; j < 4 ;j++){
                int u = fila + dx[j];
                int v = i + dy[j];
                if( u>=0 && u<R && v>=0 && v<C )
                    if( puesto[u][v] ) cont++;
            }
            if(cont!=need[fila][i]) return 0;
        }
    }
    return 1;
}

bool existelamapara(int fil,int col){
    for(int i = fil ; i >= 0 ; i--){
        if(need[i][col]!=-2) break;
        if(puesto[i][col]) return 1;
    }
    for(int i = col; i >= 0 ; i--){
        if(need[fil][i]!=-2) break;
        if(puesto[fil][i]) return 1;
    }
    return 0;
}

void pinta(int fil,int col,int color,int otro){
    for(int i = 0 ; i < 4 ; i++){
        for(int j = 0 ; j < max(R,C) ; j++){
            int u = fil + dx[i]*j;
            int v = col + dy[i]*j;
            if(u>=0&&u<R&&v>=0&&v<C){
                if(need[u][v]!=-2) break;
                if(pintado[u][v]==otro) pintado[u][v] = color;
            }
        }
    }
}

void f(int x,int y,int lamp){
    if(y==C){ x++;y=0;  }
    if(lamp>=solution) return;
    if(x==6){
        /*for(int i = 0 ; i < R ; i++){
            for(int j = 0 ; j < C ; j++){
                cout<<puesto[i][j];
            }
            puts("");
        }
        puts("");
        for(int i = 0 ; i < R ; i++){
            for(int j = 0 ; j < C ; j++){
                cout<<pintado[i][j]<<" ";
            }
            puts("");
        }
        puts("");*/
    }
    if(x>=2){
        if(!valid(x-2)) return;
    }
    if(x==R){
        if( !valid(x-1) ) return;
        int tot = 0;
        for(int i = 0 ; i < R; i++){
            for(int j = 0 ; j < C; j++){
                if(need[i][j]==-2&&pintado[i][j]>=0)tot++;
            }
        }
        if(tot!=total) return;
        /*for(int i = 0 ; i < R ; i++){
            for(int j = 0 ; j < C ; j++){
                cout<<puesto[i][j];
            }
            puts("");
        }*/
        /*for(int i = 0 ; i < R ; i++){
            for(int j = 0 ; j < C ; j++){
                cout<<pintado[i][j]<<" ";
            }
            puts("");
        }
        puts("");*/
        if(lamp<solution) solution = lamp;
        return;
    }
    if(need[x][y]!=-2) goto rr;
    if(existelamapara(x,y)) goto rr;
    puesto[x][y] = 1;
    pinta(x,y,lamp,-1);
    lamp++;
    f(x,y+1,lamp);
    lamp--;
    puesto[x][y] = 0;
    pinta(x,y,-1,lamp);
    rr:
    f(x,y+1,lamp);
    return;
}

void limpia(){
    for(int i=0;i<R;i++)for(int j=0;j<C;j++){ puesto[i][j] = 0;need[i][j] = -2; pintado[i][j] = -1; }    
}

void doit(){
    int t,x,y,c;
    solution = inf;
    limpia();
    scanf("%d",&t);
    for(int i = 0 ; i < t ; i++){
        scanf("%d%d%d",&x,&y,&c);
        x--,y--;
        need[x][y] = c;
    }
    total = R*C-t;
    f(0,0,0);
    if(solution==inf) puts("No solution");
    else printf("%d\n",solution);
}

int main(){
    while(scanf("%d%d",&R,&C)==2){
        if(R==0&&C==0) break;
        doit();
    }
}
