#include<iostream>
using namespace std;
int main()
{
	int n,m;
    cin>>n>>m;
    int x=1;
    m--;
    while(x<=n)
    {
		m=(m+x-1)%9+1;
	    int a=m;
	    for(int i=x;i<n;i++){cout<<a<<' ';a=(a-1+i)%9+1;}
	    cout<<a<<endl;
	    int y=x*2;
	    if(x!=n)for(int j=1;j<=y;j++)cout<<" ";
	    x++;
    }
}