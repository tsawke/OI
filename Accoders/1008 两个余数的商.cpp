//1008 两个数的余数和商 
#include <iostream>

using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    cout<<a%b;
    cout<<" ";
    cout<<a/b;
    cout<<".";
    cout<<(a%b*10)/b;
if(((((a%b*10)%b*10)%b*10)/b)>4)
{
    cout<<((a%b*10)%b*10)/b+1;
}
else
{
	cout<<((a%b*10)%b*10)/b;
}
    return 0;
} 
