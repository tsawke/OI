
#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[105];
int main(){
    scanf("%d",&m);
    for(int o=1;o<=m;++o){
        scanf("%d",&n);
        for(int i=1;i<=n;++i){
            scanf("%d",&a[i]);
        }
        int ans=0;
        for(int i=1;i<=n;++i){
            for(int j=n-1;j>=1;--j){
                if(a[j]>a[j+1]){
                    swap(a[j],a[j+1]);
                    ans++;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
