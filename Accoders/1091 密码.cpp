//1091 ÃÜÂë
#include<iostream>
#include<cstring>
using namespace std;
char a[60];
int main()
{
    int n,l,b,c,d,e;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        e=b=c=d=0;
        l=strlen(a);
        if(l<8&&l>16)
        {
            cout<<"   NO"<<endl;
            continue;
        }
        else
 {
            for(int j=0;j<l;j++)
            {
                if(a[j]>='a'&&a[j]<='z')
                    e=1;
                if(a[j]>='A'&&a[j]<='Z')
                    b=1;
                if(a[j]>='0'&&a[j]<='9')
                    c=1;
                if(a[j]=='~'||a[j]=='!'||a[j]=='@'||a[j]=='#'||a[j]=='$'||a[j]=='%'||a[j]=='^')
                    d=1;    
            }
            if(e+b+c+d>=3)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
    }
    return 0;
}
 
