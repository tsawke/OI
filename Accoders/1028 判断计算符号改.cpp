//1028
#include<iostream> 
#include<cstdio> 
#include<cmath> 
using namespace std;
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
if(a+b==c)
    cout<<"+";
if(a-b==c)
    cout<<"-";
if(a*b==c)
    cout<<"*";
if(a/b==c)
    cout<<"/";
if(a+b!=c && a-b!=c && a*b!=c && a/b!=c) 
    cout<<"E";
    return 0;
}
