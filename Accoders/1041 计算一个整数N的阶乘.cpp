//1041 ����һ������N�Ľ׳�
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
