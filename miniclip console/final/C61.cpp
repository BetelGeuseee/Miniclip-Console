#include<iostream>
#include<conio.h>
using namespace std;
class  large
{
	int larg[100],n;
	public: void getdata();
	friend void  calc(large x);
};
void large ::getdata()
{
	cout<<"Enter any number";
	cin>>n;
	cout<<"Enter "<<n<<" number "<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>larg[i];
	}
}
void  calc(large x)
{
	int max=x.larg[0];
	for(int i=0;i<x.n;i++)
	{
	if (x.larg[i]>max)
{
	max=x.larg[i];
}
	}
	cout<<"The large number is "<<max<<endl;
}
int main()
{
	large obj1;
	obj1.getdata();
	calc(obj1);
	return 0;
}
