#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define N 100000
#define oo 10000000
using namespace std;
int A[N];
int F[N];
int t[N][17];
int n;
int ct;
int logI(int x){
    int r=0;
    while(x){
        x/=2;
        r++;
    }
    return r-1;
}

void inicia(){
    int val=logI(ct);
    for(int j=1;j<=val;++j){
        for(int i=0;i<ct;++i){
            if( i+(1<<j) > ct )break;
            t[i][j]=max(t[i][j-1],t[i+(1<<(j-1))][j-1]);
        }
    }
}

int query(int a,int b){
    if(b<a)return -oo;
    int val=logI(b-a+1);
    return max(t[a][val],t[b-(1<<val)+1][val]);
}

int queryg(int a,int b){
    int p=lower_bound(F,F+ct,a+1)-F;
    int q=lower_bound(F,F+ct,b+1)-F;
    if(p==q)return b-a+1;
    int x=F[p]-a;
    int y=b-F[q-1]+1;
    return max(x,max(y,query(p+1,q-1)));
}

void doit(){
    ct = 0;
    int q;
    scanf("%d",&q);
    int r = oo;
    for(int i = 0 ; i < n ; i++){
        scanf("%d",&A[i]);
        if( r!=A[i] ){
            F[ct++] = i;
            r = A[i];
        }
    }
    F[ct++] = n;
    for(int i = 1 ; i <= ct ; i++) t[i][0] = F[i]-F[i-1];
    inicia();
    int a , b;
    for(int i = 0 ; i < q ; i++){
        scanf("%d%d",&a,&b);
        printf("%d\n",queryg(a-1,b-1));
    }
}

int main(){
    while(scanf("%d",&n) == 1){
        if(!n) return 0;
        doit();    
    }
}
