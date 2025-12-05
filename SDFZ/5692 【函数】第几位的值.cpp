#include <cstdio>
#include <algorithm>
using namespace std;
int digit(int n,int k){for(int i=1; i<k; i++)n/=10; return n%10;}
void InIt(){int n;int k; scanf("%d%d",&n,&k); printf("%d\n",digit(n,k));}
int main(){for(int i=1; i<=5; i++)InIt(); return 0;}
