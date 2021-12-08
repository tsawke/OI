#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <iostream>
using std::cin;
using std::cout;
using std::scanf;
using std::printf;

unsigned short a,b;char t[110];
int main(void){scanf("%d%d",&a,&b);
	if(a<10 || b<10){
		cout.setf(std::ios::right);
		cout.width(4); cout<<a; cout<<"\n";
		sprintf(t,"*%d",b); cout.width(4); cout<<t;
		cout<<"\n------\n"; cout.width(4); cout<<a*b;
		return 0;
	}
	cout.setf(std::ios::right);
	cout.width(4); cout<<a; cout<<"\n";
	sprintf(t,"*%d",b); cout.width(4); cout<<t;
	cout<<"\n------\n"; cout.width(4); cout<<a*(b%10); cout<<"\n";
	sprintf(t,"%d ",a*(b/10)); cout.width(4); cout<<t;
	cout<<"\n------\n";	cout.width(4); cout<<a*b; cout<<"\n";
	return 0;
}


