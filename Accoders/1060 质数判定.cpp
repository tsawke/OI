//1060 ÖÊÊıÅĞ¶¨
#include<iostream>
using namespace std;
int main(){
	int a,b,i,j,cnt,flag;
	cin>>a>>b;
	cnt=0;
	for(i=a;i<=b;i++){
		flag=0;
		for(j=2;j<i;j++){
			if(i%j==0)	{
				flag=1;
				break;
			}			
		}
		if(i==1)
			flag=1;
		if(flag==0)
			cnt++;
	}
	cout<<cnt;
	return 0;
}

