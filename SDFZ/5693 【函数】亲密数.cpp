#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int func(int n){int sum=0;for(int i=1; i<=n/2; i++){if(n%i==0)sum+=i;} return sum;}
void InIt(){int n; scanf("%d",&n); for(int i=2; i<=n; i++)if(i==func(func(i)) && i<func(i))printf("(%d,%d)",i,func(i));}
int main(){InIt(); return 0;}
/*
x=i; y=func(x)  func(func(x))=i
*/
