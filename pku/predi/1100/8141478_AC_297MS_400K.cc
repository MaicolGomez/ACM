#include<stdio.h>
#include<ctype.h>
char s[80];
int P[11];
int L,N,length,f;
int find(int a,int b)
{
    int r=0,l=0,i;
    for(i=b-1;i>=a;--i)
    {
        if(s[i]=='(')   ++l;
        if(s[i]==')')   ++r;
        if(l==r&&(s[i]=='+'||s[i]=='-'||s[i]=='*'))
        return i;
    }
    return -1;
}
int eval(int a,int b)
{
    int i,pos;
    pos=find(a,b);
    if(pos!=-1)
    {
        if(s[pos]=='+') return eval(a,pos)+eval(pos+1,b);
        if(s[pos]=='*') return eval(a,pos)*eval(pos+1,b);
        return eval(a,pos)-eval(pos+1,b);
    }
    if(s[a]=='(')   return eval(a+1,b-1);
    int n=0;
    for(i=a;i<b;n=n*10+s[i]-'0',++i);
    return n;
}
void combina(int pos)
{
    if(f)
    {
        if(pos==L)
        {
            if(eval(0,length)==N)
            {
                printf("%d=%s\n",N,s);
                f=0;
            }
        }
        else
        {
            s[P[pos]]='+';
            combina(pos+1);                
            s[P[pos]]='*';
            combina(pos+1);
            s[P[pos]]='-';
            combina(pos+1);
        }
    }
}
int main()
{
    int n,i,j,k,test;
    char cad[80];
    for(test=1;scanf("%d",&n)&&n;++test)
    {
        printf("Equation #%d:\n",test);
        gets(cad);
        for(i=0;cad[i]==' '||cad[i]=='=';++i);
        for(k=0;cad[i];i=j)
        {
            if((cad[i]=='('&&k&&s[k-1]==')')||(cad[i]=='('&&k&&isdigit(s[k-1]))||(isdigit(cad[i])&&k&&s[k-1]==')'))
                s[k++]=' ';
            if(cad[i]!=' ')
            {    
                s[k++]=cad[i];
                j=i+1;
            }
            else
            {
                for(j=i;cad[j]==' '&&cad[j];++j);
                if(isdigit(s[k-1])&&cad[j]&&isdigit(cad[j]))
                    s[k++]=' ';
            }
        }
        s[k]='\0';
        N=n;
        f=1;
        for(i=L=0;s[i];++i)
            if(s[i]==' ')   P[L++]=i;
        length=i;
        combina(0);
        if(f)   puts("Impossible");
        puts("");
    }
}
