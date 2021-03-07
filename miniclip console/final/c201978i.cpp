#include<iostream>
#include<conio.h>
using namespace std;
class staff
{
	char name[50];
	int  id;
	public:staff(char nam[50],int x)
	{
		strcpy(name,nam);
		id=x;
	}
	void  disp()
	{
		cout<<"Name="<<name<<endl;
		cout<<"ID="<<id<<endl;
	}
};
class lecturer:public staff
{
	char sub[50],dep[50];
	public:lecturer(char s[50],char d[50],char n[50],int a):staff(n,a)
	{
		strcpy(sub,s);
		strcpy(dep,d);
	}void disp()
	{
		
	}
};
