//1041 计算一个整数N的阶乘
#include<iostream>
using namespace std;
int main()
{
	int n,i,answer;
	cin>>n;
	answer=1;
	i=1;
for( ; i<=n; i++)
{
	answer=answer*i;
}
    cout<<answer;
    return 0;
} 
