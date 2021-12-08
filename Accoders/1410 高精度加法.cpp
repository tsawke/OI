#include <bits/stdc++.h>
using namespace std;

char a1[50005]={},b1[50005]={};
int a[50005]={},b[50005]={},c[50005]={};

int main()
{
    int lena,lenb,i;
    int lenc=0, x=0;
    cin>>a1>>b1;
    lena=strlen(a1);
    lenb=strlen(b1);
    for(i=0; i<=lena; i++) a[lena-i]=a1[i]-48;
    for(i=0; i<=lenb; i++) b[lenb-i]=b1[i]-48;
    for(int i=0; i<=50005; i++)
    {
        if(a[i]+b[i]+c[i]>=10){
            c[i+1]++;
            c[i]=(a[i]+b[i]+c[i])%10;
        }else c[i]+=a[i]+b[i];
    }
    for (int i=50005;i>=0;i--)
    {
        if(c[i]!=0){
            for (int j=i; j>=1; j--) printf("%d",c[j] );
            break;
        }
        if(a[1]+b[1]==0){
            printf("0");
            break;
        }
    }
    return 0;
}

