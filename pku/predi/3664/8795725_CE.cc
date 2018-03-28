#include<iostream>
using namespace std;
int n,k;
struct node
{
    int a;
    int b;
    int index;
};
int cmpa(const void *a,const void *b)
{
    return (*(node *)b).a-(*(node *)a).a;
}
int cmpb(const void *a,const void *b)
{
    return (*(node *)b).b-(*(node *)a).b;
}
int main()
{
    cin>>n>>k;
    struct node kan[50000];
    for(int i=0;n-i;i++)
    {
        cin>>kan[i].a>>kan[i].b;
        kan[i].index=i+1;
    }
    qsort(kan,n,sizeof(struct node),cmpa);
    qsort(kan,k,sizeof(struct node),cmpb);
    cout<<kan[0].index<<endl;
}