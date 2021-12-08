//1013 数字各位分割
#include<iostream>
using namespace std;
int main()
{
	int x;
	cin>>x;
	cout<<x/1000;
	cout<<" ";
	cout<<x%1000/100;
	cout<<" ";
	cout<<x%1000%100/10;
	cout<<" ";
	cout<<x%1000%100%10/1;
	return 0;
}
