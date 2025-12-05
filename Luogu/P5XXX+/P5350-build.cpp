//https://www.luogu.com.cn/discuss/358903
#include <stdio.h>
#include <algorithm>
#include <time.h>
typedef long long ll;
ll seed;
ll rnd(){
    ll ret=seed;
    seed=(seed*7+13)%(1000000007);
    return ret%(1000000007);
}
int n,m;
int len=300001;
int l1,l2,r1,r2;
int a[5];
void swap(int &a,int &b){
    a^=b;
    b^=a;
    a^=b;
}
void make(){
    for (int i=1;i<=3;i++){
        a[i]=rnd()%len+1;
    }
    if (a[1]==a[2]||a[1]==a[3]||a[2]==a[3]) make();
    std::sort(a+1,a+4);
    a[4]=a[3]+a[2]-a[1];
    if (a[4]>len)   make();
    l1=a[1],r1=a[2],l2=a[3],r2=a[4];
}
int main(){
    freopen("in.txt","w",stdout);
    scanf("%d%d",&len,&m);
    seed=(unsigned)time(0);
    printf("%d %d\n",len,m);
    for (int i=1;i<=len;i++){
        printf("%lld ",rnd());
    }
    printf("\n");
    for (int i=1;i<=m;i++){
        int op=rnd()%6+1;
        printf("%d ",op);
        switch (op){
            case 1:{
                int l=rnd()%len+1,r=rnd()%len+1;
                if (l>r)    swap(l,r);
                printf("%d %d\n",l,r);
                break;
            }
            case 2:{
                int l=rnd()%len+1,r=rnd()%len+1,val=rnd();
                if (l>r)    swap(l,r);
                printf("%d %d %d\n",l,r,val);
                break;
            }
            case 3:{
                int l=rnd()%len+1,r=rnd()%len+1,val=rnd();
                if (l>r)    swap(l,r);
                printf("%d %d %d\n",l,r,val);
                break;
            }
            case 4:{
                make();
                printf("%d %d %d %d\n",l1,r1,l2,r2);
                break;
            }
            case 5:{
                make();
                printf("%d %d %d %d\n",l1,r1,l2,r2);
                break;
            }
            case 6:{
                int l=rnd()%len+1,r=rnd()%len+1;
                if (l>r)    swap(l,r);
                printf("%d %d\n",l,r);
                break;
            }
        }
    }
    return 0;
}