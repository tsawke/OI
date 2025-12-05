//1080 Êı×éµÄ¾àÀë
#include<cstdio>
#include<cmath>
using namespace std;
int a[500005];
int main (){
    int n,m;
    int ans=9999999;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)    {
        scanf("%d",&a[i]);
    }
        for(int i=1;i<=m;i++) {
        int b;
        scanf("%d",&b);
        for(int j=1;j<=n;j++)        {
            ans=(ans<abs(b-a[j])?ans:abs(b-a[j]));
            if(a[j]>b) break;
        }
    }
    printf("%d",ans);
    return 0;
}
 
