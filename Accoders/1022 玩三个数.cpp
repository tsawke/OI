//1026 �������� 
#include <iostream>
using namespace std;
int main()
{
	int f,a,b,c,t;
	cin>>f>>a>>b>>c;
//����a����С��b���м䣬c�������ʱ����t�������������� 
if(a>b)
{
	t=b;
	b=a;
	t=a;
}
if(a>c)
{
	t=a;
	a=c;
	c=t;
}
if(b>c)
{
	t=b;
	b=c;
	c=t;
}
if(f==1)
{
	cout<<a;
}
else
{
	cout<<b;
}
    return 0;
} 
