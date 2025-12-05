//3036 ∂‡…ŸÃÏ
#include<iostream>
using namespace std;
int main()
{
	int year,month;
	cin>>year>>month;
	if(year%100==0)
	{
		if(year%400==0)
		{
			if(month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12)
			{
				cout<<"31";
			}
			else
			{
				if(month==4 || month==6 || month==9 || month==11)
				{
					cout<<"30";
				}
				else
				{
					cout<<"29";
				}
			}
		}
		else
		{
		if(month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12)
			{
				cout<<"31";
			}
			else
			{
				if(month==4 || month==6 || month==9 || month==11)
				{
					cout<<"30";
				}
				else
				{
					cout<<"28";
				}
			}	
		}
	}
	else
	{
		if(year%4==0)
		{
		if(month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12)
			{
				cout<<"31";
			}
			else
			{
				if(month==4 || month==6 || month==9 || month==11)
				{
					cout<<"30";
				}
				else
				{
					cout<<"29";
				}
			}
		}
		else
		{
		if(month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12)
			{
				cout<<"31";
			}
			else
			{
				if(month==4 || month==6 || month==9 || month==11)
				{
					cout<<"30";
				}
				else
				{
					cout<<"28";
				}
			}	
		}
	}
    return 0;
} 
