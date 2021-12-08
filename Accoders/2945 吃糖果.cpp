//2945 Ётлг╧Ш 
#include <bits/stdc++.h>
using namespace std;int a[30];int f(int n){a[1]=1; a[2]=2; for(int i=3; i<=n; i++) a[i]=a[i-1]+a[i-2]; return a[n];}int main(){int n; scanf("%d",&n); printf("%d\n",f(n)); return 0;} 
