//1075 Со»ФИэЅЗ
#include<iostream>
using namespace std;
int main(){
    int n,a[31][31];
    while(cin>>n)    {
        for(int i=0;i<n;i++)       {
            a[i][0]=a[i][i]=1;
        }
        for(int i=2;i<=n-1;i++)        {
            for(int j=1;j<=i-1;j++)          {
                a[i][j]=a[i-1][j]+a[i-1][j-1];
            }
        }
        for(int i=0;i<n;i++)       {
            for(int j=0;j<=i;j++)        {
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}
 
