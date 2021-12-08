//1047 分解质因数
#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int k;
	cin>>k;
	int A=sqrt(k);
	if(k<2)
	    cout<<"Error"; 
	else
	{
		if(k==2)
		    cout<<"2";
		else
		{
			if(k==4)
			    cout<<"2*2";
			else
			{
				    int i=2;	
				for( ; i<A; i++)
				{
					while(k!=i)
					{
						if(k%i==0)
						{
							cout<<i<<"*";
							k=k/i;
						}
						else
						{
							break;
						}
					}
				    
				}
			if(k/A==A)
			    cout<<A<<"*"<<A;
			else
			    cout<<k;
			} 
		}
	}
    return 0;
} 
