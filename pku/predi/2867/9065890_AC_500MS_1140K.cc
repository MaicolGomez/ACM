#include<vector>
#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
vector<int>v;
int n;
int cont = 0;
void doit(){
    cont++;
    int t,x,y;
    v.clear();
    for(int i = 0 ; i < n ; i++) v.push_back(i+1);
    scanf("%d",&t);
    for(int i = 0 ; i < t ; i++){
        scanf("%d%d",&x,&y);
        reverse(v.begin()+x-1,v.begin()+y);
    }
    int q;
    scanf("%d",&q);
    printf("Genome %d\n",cont);
    //for(int i = 0 ; i < n ; i++)cout<<v[i]<<" ";
    //cout<<endl;
    for(int i = 0 ; i < q ; i++){
        scanf("%d",&x);
        int k;
        for(int i = 0 ; i < n ; i++) if( v[i]==x ){k=i+1;break;}
        printf("%d\n",k);
    }
}

int main(){
    while( scanf("%d",&n)==1 ){
        if(!n)break;
        doit();
    }
}
