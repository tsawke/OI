//1058 ¾¯²ì×¥Ð¡Íµ
#include<iostream>
using namespace std;

int main()
{
	int i;
	for(i=1;i<5;i++)
	{
		if(((i!=1)+(i==3)+(i==4)+(i!=4))==3)
			cout<<(char)(i-1+'A');
	}
	return 0;
}
 
