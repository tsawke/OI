//1151 æÿ’Û≥À∑®
#include<iostream>
using namespace std;
#define LL long long
 
const LL Mod = 1e9 + 7;
LL a[101][101],b[101][101],c[101][101];
LL Bmod(LL a, LL b) {
    LL ret = a % b;
    while(ret < 0) ret += b;
    return ret;
}

int main()
{
    int m,n,k;
    LL t=0;
    cin>>n>>m>>k;
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }    
    
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<k;j++)
        {
            cin>>b[i][j];
        }
    }
 
   for(int i=0;i<n;i++)
    {
        for(int j=0;j<k;j++)
        {
        	t=0;
            for(int L=0;L<m;L++)
            {
                t=Bmod(t+a[i][L]*b[L][j],Mod);
            }
            c[i][j]=t;            
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<k;j++)
        {
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
 
