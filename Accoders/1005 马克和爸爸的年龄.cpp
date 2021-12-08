//1005 马克和爸爸年龄 
#include <iostream>
using namespace std;
int main()
{
    int n,x;
    cin>>n>>x;
    cout<<((n-3*2)-x)/2+3;
    cout<<" ";
    cout<<n-(((n-3*2)-x)/2+3);
    return 0;
} 
