#include<iostream.h>
#include<conio.h>
using namespace std;
class large
{
	int i,n,a[50];
	public:void read();
	void disp();
};
void large::read()
	{
		cout<<"Enter the value of n";
		cin>>n;
		for(i=1;i<=n;i++)
		{
		cin>>a[i];	
		}
	}
	void large:: disp()
	{
		int lar=a[1];
		for(i=1;i<=n;i++)
		{
	if(lar>a[i])
	lar=a[i];}
    }
cout<<"Largest="<<lar;
}
int main()
{
	large l;
	l.read();
	l.disp();
	getch();
	return 0;
}
