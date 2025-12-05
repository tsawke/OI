//1076 ÉßĞÎÊıÁĞ
#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int x,y,s,a[21][21],t=1;
	cin>>s;
	for(int i=s;i>=1;i--)	{
		x=i;
		y=1;
		for(int j=1;j<=s+1-i;j++)		{
			a[x][y]=t;
			t++;
			x++;
			y++;
		}
	}
	for(int i=1;i<=s;i++)
	{
		for(int j=1;j<=i;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
 
