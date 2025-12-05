//1082 ÂÝÐý¾ØÕó
#include<iostream>
using namespace std;
int n;
int w[1002][1002];
int main()
{
    cin>>n;
    int c;
    if(n%2==1)c=(n+1)/2;
    else c=n/2;
    w[c][c]=1;
    int d=1;
    for(int j=1;j<=c;j++)
    {
            for(int k=j;k<=n-j+1;k++)
            w[j][k]=d++;
            for(int k=j+1;k<=n-j+1;k++)
            w[k][n-j+1]=d++;
 for(int k=n-j;k>=j;k--)
            w[n-j+1][k]=d++;
            for(int k=n-j;k>=j+1;k--)
            w[k][j]=d++;
              
    }
    for(int i=1;i<=n;i++)
    {
         for(int j=1;j<=n;j++)
         {
            cout<<w[i][j]<<" "; 
         }
         cout<<endl;
    }
    return 0;
}
 
