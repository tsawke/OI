//2887 µ¹ÐòÊý 
#include<bits/stdc++.h>
void f(int n){ 
    int a;
    a=n%10;
    printf("%d",a);
    n=(n-a)/10;
    if(n==0) return;
    f(n);  
}
 
int main()
{
    int a;
    scanf("%d",&a);
    f(a);
}
