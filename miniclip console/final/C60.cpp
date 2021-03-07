#include<iostream>
#include<conio.h>
using namespace std;
class comp;
class complex
{
	int real,imag;
	public:void getdata();
	friend void  calc(complex a,comp b);
};
class comp
{
	int re,im;
	public: void getdata();
	friend void calc(complex a,comp b);
};
void complex ::getdata()
{
	cout<<"Enter the first complex number:" ;
	cin>>real>>imag;
}
void comp :: getdata()
{
	cout<<"Enter the second complex number:";
	cin>>re>>im;
}
 void calc(complex a,comp b)
{
	int real,imaginary;
	real=a.real+b.re;
	imaginary=a.imag+b.im;
	cout<<"The addition of complex number is:"<<real <<"+i"<<imaginary;
}
int main()
{ complex obj1; comp obj2;
obj1.getdata();
obj2.getdata();
calc(obj1,obj2);
return 0;}
  
