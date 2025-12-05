//1144 谁参加了信息奥赛
#include<iostream>
using namespace std;
int main()
{
	int a,b,c,d,e;
	for(a=0;a<=1;a++)
	   for(b=0;b<=1;b++)
	      for(c=0;c<=1;c++)
		for(d=0;d<=1;d++)
	 	  for(e=0;e<=1;e++)
		    {	
			if(a==b && (b+c)==1 && (c-d)==0 && (d+e)>0 &&(a+d+e==3 || e==0) ){
			if(a==1) cout<<"A";
			if(b==1) cout<<"B";
			if(c==1) cout<<"C";
			if(d==1) cout<<"D";
			if(e==1) cout<<"E";
			}
            }
    return 0;
    }
 
