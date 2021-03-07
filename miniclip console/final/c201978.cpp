#include<iostream>
#include<conio.h>
using namespace std;
class student
{
protected:char name[50],fac[50];
	int rollno;
	public: void getdata()
	{
		cout<<"Enter the name of student"<<endl;
		cin>>name;
		cout<<"Enter the faculty of student"<<endl;
		cin>>fac;
		cout<<"Enter the roll no of student"<<endl;
		cin>>rollno;	 
		} 
		void disp()
		{
			cout<<"Name ="<<name<<"Faculty="<<fac<<"Rollno="<<rollno<<endl;
		}
};
class exam:public student
{
	protected: float m1,m2,m3,m4,m5;
	public: void getdata()
	{
		cout<<"Enter the marks of 5 subjects:"<<endl;
		cin>>m1>>m2>>m3>>m4>>m5;
	}
	void disp()
	{
		cout<<"Marks are:"<<endl;
		cout<<m1<<endl;
		cout<<m2<<endl;
		cout<<m3<<endl;
		cout<<m4<<endl;
		cout<<m5<<endl;
		}	
};
class result:public exam
{
	protected:float total,per;
	public: void getdata()
	{student::getdata();
	exam::getdata();
		total=m1+m2+m3+m4+m5;
		per=total/5.0;
	}
	void disp()
	{
		student::disp();
		exam::disp();
		cout<<"Total="<<total;
		cout<<"Percentage="<<per;
	}
};
int main()
{
	result r;
	r.getdata();
	r.disp();
	return 0;
}
