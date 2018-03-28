#include<cstdio>

int n;
long long fac[14];
void llena(){
    fac[0] = 1;
    for(int i = 1 ; i <= 12 ; i++ ){
        fac[i] = fac[i-1] * i;
    }
}
bool son[14];
bool mira(){
    if(n == 0 ) return 0;
    for(int i = 9 ; i >= 0 ; i-- )
        if( n >= fac[i] ) n-= fac[i];
        
    if(n == 0) return 1;
    return 0;
}
int main(){
    llena();
    int tc;
    scanf("%d",&tc);
    while( tc-- ){
        scanf("%d",&n);
        if( mira() ) printf("YES\n");
        else printf("NO\n");
    }
}
