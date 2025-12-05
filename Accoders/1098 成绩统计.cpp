//1098 ³É¼¨Í³¼Æ
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

struct student
{
	int num;
	char name[60];
	int x,y,z,a;
};

struct student s[310];

int main()
{
	int n,sx,sy,sz,m=1;
	sx=sy=sz=0;
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		cin>>s[i].num>>s[i].name>>s[i].x>>s[i].y>>s[i].z;
		s[i].a=(s[i].x+s[i].y+s[i].z)/3;
		if(s[i].a>s[m].a)
		m=i;
		sx=sx+s[i].x;
		sy=sy+s[i].y;
		sz=sz+s[i].z;
	}
	cout<<sx/n<<" "<<sy/n<<" "<<sz/n<<endl;
	cout<<s[m].num<<" "<<s[m].name<<" "<<s[m].x<<" "<<s[m].y<<" "<<s[m].z;
	return 0;
	
	
	
}
