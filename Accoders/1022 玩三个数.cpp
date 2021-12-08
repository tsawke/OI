//1026 玩三个数 
#include <iostream>
using namespace std;
int main()
{
	int f,a,b,c,t;
	cin>>f>>a>>b>>c;
//假设a是最小，b是中间，c是最大，临时变量t，给三个数排序 
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
