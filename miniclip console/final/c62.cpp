#include<iostream>
#include<conio.h>
using namespace std;
class second;
class first
{
	int ft,inc;
	public: void getdata()
	{
		cout<<"Enter the distance in feet and inch";
		cin>>ft>>inc;
	}
	friend void calc(first x, second y);
};
class second
{
	int ft,inc;
	public: void getdata()
	{
		cout<<"Enter the distance in feet and inch";
		cin>>ft>>inc;
	}
	friend void calc(first x,second y);
};
void calc(first x,second y)
{
	int f,i;
	f=x.ft+y.ft;
	i=x.inc+y.inc;
	if(i>=12){
		f++;
		i-=12;
	}
	cout<<"The distance is "<<f<<"."<<i;
}
int main()
{
	first obj1;second obj2;
	obj1.getdata();
	obj2.getdata();
	calc(obj1,obj2);
	return 0;
}
