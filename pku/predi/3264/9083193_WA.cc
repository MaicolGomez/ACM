#include<vector>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<cmath>
using namespace std;
#define ll (long long)
#define MAXN 50002

int A[MAXN];
int M[MAXN][20];
int MM[MAXN][20];
int Q;

void f(int N){
      for (int i = 0; i < N; i++)
          M[i][0] = i;
      for (int j = 1; 1 << j <= N; j++)
          for (int i = 0; i + (1 << j) - 1 < N; i++)
              if (A[M[i][j - 1]] < A[M[i + (1 << (j - 1))][j - 1]])
                  M[i][j] = M[i][j - 1];
              else
                  M[i][j] = M[i + (1 << (j - 1))][j - 1];
}

void ff(int N){
      for (int i = 0; i < N; i++)
          MM[i][0] = i;
      for (int j = 1; 1 << j <= N; j++)
          for (int i = 0; i + (1 << j) - 1 < N; i++)
              if (A[MM[i][j - 1]] > A[MM[i + (1 << (j - 1))][j - 1]])
                  MM[i][j] = MM[i][j - 1];
              else
                  MM[i][j] = MM[i + (1 << (j - 1))][j - 1];
}

int main(){
    int N,x,y;
    scanf("%d%d",&N,&Q);
    for(int i=0;i<N;i++) scanf("%d",&A[i]);
    f(N);
    ff(N);
    for(int i=0;i<Q;i++){
        scanf("%d%d",&x,&y);
        x--,y--;
        int k = int(log(y - x + 1));
        int mini,maxi;
        if( A[M[x][k]] <= A[ M[y-(1<<k)+1][k] ] ) mini = M[x][k];
        else mini = M[y-(1<<k)+1][k];
        if( A[MM[x][k]] >= A[MM[y-(1<<k)+1][k]] ) maxi = MM[x][k];
        else maxi = MM[y-(1<<k)+1][k];
        printf("%d\n",A[maxi]-A[mini]);
    }
}
