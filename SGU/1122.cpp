#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <ctime>
#include <cstring>
#include <ctype.h>
#include <memory>
#include <fstream>
#include <string>

#include <map>
#include <queue>
#include <stack>
#include <iomanip>
#include <vector>
#include <list>
#include <deque>
#include <set>
//#include <conio.h>
#define oo 2000000000
#define ol 200000000000000000ll
#define ooo 1E14
#define EPS 1E-10
/*#define dis(x1,y1,x2,y2)\
 (double)(sqrt( ((x1)-(x2))*((x1)-(x2)) + ((y1)-(y2))*((y1)-(y2)) ) )
#define disx(x,y) (double)(sqrt((x)*(x)+(y)*(y)))
#define dianji(x1,y1,x2,y2) (double)((x1)*(x2)+(y1)*(y2))
#define chaji(x1,y1,x2,y2) (double)((x1)*(y2)-(y1)*(x2))*/
using namespace std;
const double PI=acos((double)-1);
typedef long long LL;
int ts,ts2;
int n,m;
char a[2000005],b[2000005],ar[2000005],br[2000005];
LL gcd(LL x,LL y){LL t;for(;y!=0;){t=x%y;x=y;y=t;}return x;}
void extendKMP(int n,char *a,int m,char *b,int *next,int *ex)
{
     int i,j,k,t1,t2,t3,t4,t5,t,farP=1,farI=2;
     next[0]=next[1]=0;
     for(i=2;i<=m;i++)
     {
            if (farP<i)
             farP=i-1;
            else
            {
            t1=next[i-farI+1];
            if (t1<farP-i+1)
            {
                next[i]=t1;continue;
            }
            }
            for(j=farP-i+2;i+j-1<=m;j++)
             if (b[i+j-1]!=b[j])
             {
                    break;
                }
            next[i]=j-1;farP=(j-1)+i-1;farI=i;
        }
  farP=0;
        for(i=1;i<=n;i++)
        {
            if (i==94)
             ts=0;
            if (farP<i)
             farP=i-1;
            else
            {
                t1=next[i-farI+1];
                if (t1<farP-i+1){ex[i]=t1;continue;}
         }
            for(j=farP-i+2;i+j-1<=n&&j<=m;j++)
             if (a[i+j-1]!=b[j])break;
            j--;ex[i]=j;farP=j+i-1;farI=i;
        }
        ts=0;
}
int tmp[2000005],ex[2000005],ex2[2000005];
void work(int pos)
{
     int i,j,k,t1,t2,t3,t4,t5,t;
     t1=ex[pos];
     t3=(pos+m-2)%n+1;t3=n-t3+1;
     t2=ex2[t3];
     if (pos==3)
      ts=0;
     if (t1+t2+1>=m)
     {
            for(i=pos;i<=n;i++)printf("%c",a[i]);    for(i=1;i<=pos-1;i++)printf("%c",a[i]);
            exit(0);
        }
}
int main(){
  int i,j,k,t1,t2,t3,t4,t5,t,tag,mPos;
  double u1,u2,u3,u4,u5;
  char c1,c2,c3;
  while( scanf("%d%d%*c",&n,&m)  == 2 ){
  a[0]=' ';gets(a+1);
  if (a[1]=='\0'||a[1]==' ')gets(a+1);
  b[0]=' ';gets(b+1);
  n=strlen(a+1);m=strlen(b+1);
  for(i=1;i<=m;i++)b[i+m]=b[i];
  tag=1,i=1,j=1;
  for(;;)
  {
            if (i==j)j++;
            if (i>m||j>m)break;
            for(k=0;;k++)
            {
                if (b[i+k]!=b[j+k]||k>=m)
                {
                    if (b[i+k]<=b[j+k])
                    {
                        if (b[i+k]==b[j+k]&&i>j)swap(i,j);
                        j=j+k+1;
                    }
                    else i=i+k+1,swap(i,j);
                    break;
                }
            }
     }
     if (tag==2)i=j;mPos=i;
     for(i=1;i<=m;i++)b[i]=b[m+(mPos+i-2)%m+1];
     b[m+1]='\0';printf("%s\n",b+1);
     
     for(i=1;i<=n;i++)a[i+n]=a[i],ar[i]=ar[i+n]=a[n-i+1];
     for(i=1;i<=m;i++)br[i]=br[i+m]=b[m-i+1];
     extendKMP(2*n,a,m,b,tmp,ex);
     extendKMP(2*n,ar,m,br,tmp,ex2);
     for(i=1;(i-1)*2<=n;i++)
     {
            j=i;
            work(j);
            j=n-i+1;
            work(j);
        }
            cout << "\n";
    }
     
  return 0;
}

