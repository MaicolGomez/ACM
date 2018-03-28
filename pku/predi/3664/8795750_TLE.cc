#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class cow
{
public:
	long a;
	long b;
	long index;
	cow(long a,long b,long index)
	{
		this->a = a;
		this->b = b;
		this->index = index;
	}
};
bool order(cow a,cow b);
vector<cow> all;
int main()
{
	long n,k,i,a,b,output;
	cin>>n>>k;
	for(i = 0 ; i < n ; i ++)
	{
		cin>>a>>b;
		all.push_back(*(new cow(a,b,i + 1)));
	}
	sort(all.begin(),all.begin() + n,order);
	output = 0;
	for( i = 1 ; i < k ; i++)
		if(all[output].b < all[i].b)
			output = i;
	cout<<all[output].index;
	return 0;
}
bool order(cow a,cow b)
{
	return a.a > b.a;
}