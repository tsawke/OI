#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	printf("%d\n",max(max(a,b),c));
    return 0;
} 
