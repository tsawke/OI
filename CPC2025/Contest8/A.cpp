#include<bits/stdc++.h>
#define N 300000
#define swap(x,y) (x^=y^=x^=y)
using namespace std;
int n,a[N+5];
// class Class_FIO
// {
//     private:
//         #define Fsize 100000
//         #define tc() (A==B&&(B=(A=Fin)+fread(Fin,1,Fsize,stdin),A==B)?EOF:*A++)
//         #define pc(ch) (FoutSize<Fsize?Fout[FoutSize++]=ch:(fwrite(Fout,1,Fsize,stdout),Fout[(FoutSize=0)++]=ch))
//         int Top,FoutSize;char ch,*A,*B,Fin[Fsize],Fout[Fsize],Stack[Fsize];
//     public:
//         Class_FIO() {A=B=Fin;}
//         inline void read(int &x) {x=0;while(!isdigit(ch=tc()));while(x=(x<<3)+(x<<1)+(ch&15),isdigit(ch=tc()));}
//         inline void writeln(int x) {while(Stack[++Top]=x%10+48,x/=10);while(Top) pc(Stack[Top--]);pc('\n');}
//         inline void clear() {fwrite(Fout,1,FoutSize,stdout),FoutSize=0;}
// }F;
class Class_LCT
{
    private:
        #define LCT_SIZE N
        #define PushUp(x) (node[x].Sum=max({node[x].Val, node[node[x].Son[0]].Sum, node[node[x].Son[1]].Sum}))
        #define Rever(x) (swap(node[x].Son[0],node[x].Son[1]),node[x].Rev^=1)
        #define PushDown(x) (node[x].Rev&&(Rever(node[x].Son[0]),Rever(node[x].Son[1]),node[x].Rev=0))
        #define Which(x) (node[node[x].Father].Son[1]==x)
        #define Connect(x,y,d) (node[node[x].Father=y].Son[d]=x)
        #define IsRoot(x) (node[node[x].Father].Son[0]^x&&node[node[x].Father].Son[1]^x)
        #define MakeRoot(x) (Access(x),Splay(x),Rever(x))
        #define Split(x,y) (MakeRoot(x),Access(y),Splay(y)) 
        int Stack[LCT_SIZE+5];
        struct Tree
        {
            int Val,Sum,Father,Rev,Son[2];
        }node[LCT_SIZE+5];
        inline void Rotate(int x)
        {
            register int fa=node[x].Father,pa=node[fa].Father,d=Which(x);
            !IsRoot(fa)&&(node[pa].Son[Which(fa)]=x),node[x].Father=pa,Connect(node[x].Son[d^1],fa,d),Connect(fa,x,d^1),PushUp(fa),PushUp(x);
        }
        inline void Splay(int x)
        {
            register int fa=x,Top=0;
            while(Stack[++Top]=fa,!IsRoot(fa)) fa=node[fa].Father;
            while(Top) PushDown(Stack[Top]),--Top;
            while(!IsRoot(x)) fa=node[x].Father,!IsRoot(fa)&&(Rotate(Which(x)^Which(fa)?x:fa),0),Rotate(x);
        }
        inline void Access(int x) {for(register int son=0;x;x=node[son=x].Father) Splay(x),node[x].Son[1]=son,PushUp(x);}
        inline int FindRoot(int x) {Access(x),Splay(x);while(node[x].Son[0]) PushDown(x),x=node[x].Son[0];return Splay(x),x;}
    public:
        inline void Init(int len,int *data) {for(register int i=1;i<=len;++i) node[i].Val=data[i];}
        inline void Link(int x,int y) {MakeRoot(x),FindRoot(y)^x&&(node[x].Father=y);}
        inline void Cut(int x,int y) {MakeRoot(x),!(FindRoot(y)^x)&&!(node[y].Father^x)&&!node[y].Son[0]&&(node[y].Father=node[x].Son[1]=0,PushUp(x));}
        inline void Update(int x,int v) {Splay(x),node[x].Val=v;}
        // inline int Query(int x,int y) {return Split(x,y),node[y].Sum;}
        int Query(int x) {return node[x].Sum;}
}LCT;

template<typename T = int>
inline T read(void){
    T ret(0);
    short flag(1);
    char c = getchar();
    while(c != '-' && !isdigit(c))c = getchar();
    if(c == '-')flag = -1, c = getchar();
    while(isdigit(c)){
        ret *= 10;
        ret += int(c - '0');
        c = getchar();
    }
    ret *= flag;
    return ret;
}

basic_string < int > p[110000];

int main()
{
    //////////////////////////
    int n = read(), M = read(), Q = read();
    for(int i = 1; i <= n; ++i)p[i] += {0, M + 2};
    while(Q--){
        int opt = read();
        if(opt == 1){
            int a = read(), b = read();
            auto it = lower_bound(p[a].begin(), p[a].end(), b);
            
        }
    }


    //////////////////////////

    register int query_tot,i,op,x,y;
    for(F.read(n),F.read(query_tot),i=1;i<=n;++i) F.read(a[i]);
    for(LCT.Init(n,a);query_tot;--query_tot)
    {
        F.read(op),F.read(x),F.read(y);
        switch(op)
        {
            case 0:F.writeln(LCT.Query(x,y));break;
            case 1:LCT.Link(x,y);break;
            case 2:LCT.Cut(x,y);break;
            case 3:LCT.Update(x,y);break;
        }
    }
    return F.clear(),0;
} 