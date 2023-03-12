#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=100010,FSIZE=1<<20,fx[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
int n,len[N],sts;
struct{
    int x;    // 该层对应的矩形编号
    bool y;   // 该层外面两边的方向
}st[N];       // 栈
struct point{int x,y;}ans[N];
vector<int> a;
bool s[N];
struct sqr{
    int w,h,lx,ly,nx,ny,x,y;
    void operator+=(const sqr &b){
        if(!len[ny]) len[ny]=ly+b.lx-1;  // 将两个线段无转角地合并
        *this=sqr{w+b.w,                 // 宽度直接相加
                  max(h-y,b.h-b.x)+
                      max(y,b.x),        // 高度注意中间合并的线段位置会对结果造成影响
                  lx,b.ly,nx,b.ny,       // 复制信息
                  x+max(b.x-y,0),
                  b.y+max(y-b.x,0)       // 修正新的位置
                 };
    }

    // 0 表示左端点左转，1 表示左端点右转
    sqr operator^(bool b){
    // 转向之后左右两条边的长度就固定了，丢到答案上
    if(!len[nx]) len[nx]=lx;
    if(!len[ny]) len[ny]=ly;
    
    return(sqr{h,
               w+2,       // 旋转 90 度之后长宽互换，并且高度 +2
               b?h-x+1:x,
               b?y:h-y+1, // 按照方向讨论一下，这里不放图了自己手画一下
               nx-1,
               ny+1,      // 编号移动一下
               b?1:w+2,
               b?w+2:1    // 位置调整，自己手画一下
              });
    }
    void Print(void){
    printf("sq: %d %d %d %d %d %d %d %d\n", w, h, lx, ly, nx, ny, x, y);
    }
}d[N];
char BuF[FSIZE],*InF=BuF;
template<typename T>void read(T &x){
    for(;*InF<33;++InF);
    for(x=0;*InF>32;x=x*10+(*InF++^48));
}
sqr solve(int l,int r){
    printf("solving l = %d, r = %d\n", l, r);
    if(l>r)
        return(sqr{0,1,0,0,0,0,0,0});
    for(d[0]=sqr();l<=r;++l){
        if(sts&&s[l]!=st[sts].y){   // 这里需要魔改一下括号序的弹栈规则
            if(!d[sts--].w){        // 如果下一层矩形为空
                d[sts+1]={1,2,1,1,l-1,l+1,s[l]?1:2,s[l]?2:1};
                len[l]=1;
            }else
                d[sts+1]=d[sts+1]^s[l];    // 旋转
            if(!d[sts].w)
                d[sts]=d[sts+1];    // 如果当前层矩形为空直接复制
            else
                d[sts]+=d[sts+1];   // 否则合并
            d[sts+1]=sqr();
        }else{
            st[++sts]={l,s[l]};
            d[sts]=sqr();
        }
        printf("$$$ size = %d\n", sts);
    }d[0].Print();
    return(d[0]);
}
void calc(int m){    // 按照当前的长度情况模拟出答案各点的坐标
    ans[m]={0,0};
    for(int i=m,f=0;i<=n;++i){
        // printf("# i = %d, (%d, %d)\n", )
        ans[i+1]={ans[i].x+fx[f][0]*len[i],ans[i].y+fx[f][1]*len[i]};
        printf("# i = %d, (%d, %d)\n", i + 1, ans[i + 1].x, ans[i + 1].y);
        if((s[i]?++f:--f)>3) f=0;
        else if(f<0) f=3;
    }
}
void work(){
    int L=0,R=0,m=1,p=0;
    for(int i=1;*InF>32;(s[i++]=*InF++=='P')?++R:++L,++n);
    if(L-R!=4){
        printf("NIE\n");
        return;
    }

    // 将左边的 R 移到右边
    for(a.clear();s[m];s[++n]=s[m++]);

    // 找到四个端点
    for(int i=m,d=0;a.size()<4;++i)
        if(!d&&s[i]==s[m]) a.push_back(i);
        else s[i]==s[m]?++d:--d;
    for(int i = 0; i <= 3; ++i)printf("a: %d\n", a[i]);
    // 计算四个矩形
    len[a[0]]=(solve(a[0]+1,a[1]-1)^0).lx+N;
    printf("len %d = %d\n", 1, len[a[0]]);
    len[a[1]]=(solve(a[1]+1,a[2]-1)^0).lx+N;
    len[a[2]]=(solve(a[2]+1,a[3]-1)^0).lx+N;
    len[a[3]]=(solve(a[3]+1,n     )^0).lx+N;
    // 进行一次模拟
    printf("\n\n LEN : \n");
    for(int i = m; i <= n; ++i)printf("%d ", len[i]);
    printf("\n\n\n");
    calc(m);

    // 修正 x
    if(ans[n+1].x>0)
        len[a[0]]+=ans[n+1].x;
    else
        len[a[2]]-=ans[n+1].x;

    // 修正 y
    if(ans[n+1].y>0)
        len[a[1]]+=ans[n+1].y;
    else
        len[a[3]]-=ans[n+1].y;

    // 计算答案
    for(calc(m);m>1;ans[--m]=ans[n--]);
    for(int i=m+p;i<=n;++i) printf("i = %d, %d %d\n",i, ans[i].x,ans[i].y);
}
int main(){
    fread(BuF,1,FSIZE,stdin);
    work();
    return(0);
}
