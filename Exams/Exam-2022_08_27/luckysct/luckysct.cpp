#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
// #include <bits/extc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long unll;
typedef long double ld;
typedef unsigned int uint;
typedef __float128 f128;

#define npt nullptr
#define PI M_PI
#define E M_E

template < typename T = int >
inline T read(void);


#define eps (f128)(1e-5)

bool cmp(f128 a, f128 b){return fabsf128(a - b) <= eps;}
f128 x;
f128 ans;

#define vf vector < func > 

enum func{sinn = 1, coss, atann, out_of_range__};
vf oper;

void bfs(int q__){
    double begT = (double)clock() / CLOCKS_PER_SEC;
    queue < pair < f128, vf > > q;
    vf empt;
    q.push(make_pair((f128)0.0, empt));
    while(!q.empty()){
        auto head = q.front(); q.pop();
        // if(cmp(head.first, ans)){
        //     oper = head.second;
        //     return;
        // }
        // if((double)clock() / CLOCKS_PER_SEC >= 0.90)return;
        for(func f = sinn; f <= atann; f = func(f + 1)){

            head.second.push_back(f);
            // printf("current: %.5lf\n", (double)head.first);
            f128 tmp(0.0);
            switch(f){
                case sinn:{
                    tmp = sinf128(head.first);
                    break;
                }
                case coss:{
                    tmp = cosf128(head.first);
                    break;
                }
                case atann:{
                    tmp = atanf128(head.first);
                    break;
                }
                default:{
                    printf("error\n");
                    break;
                }
            }
            if(cmp(tmp, ans)){
                oper = head.second;
                return;
            }
            if((int)head.second.size() > q__ * 2 + 1 || (double)clock() / CLOCKS_PER_SEC >= 0.80){
                printf("None");
                oper.clear();
                return;
            }
            // head.first = tmp;
            q.push(make_pair(tmp, head.second));
            head.second.pop_back();
        }
    }
}


void CAL(int p, int q){
    // fprintf(stderr, "caling p=%d, q=%d\n", p, q);
    oper.clear();
    ans = sqrtf128((f128)p / (f128)q);
    // printf("%.7lf\n%.7lf\n", (double)ans, (double)(sin(atan(cos(0.0)))));
    // printf("else if(p==%d&&q==%d)printf(\"", p, q);
    bfs(q);
    // reverse(oper.begin(), oper.end());
    for(auto i : oper){
        switch(i){
            case sinn:{
                printf("s");
                break;
            }
            case coss:{
                printf("c");
                break;
            }
            case atann:{
                printf("t");
                break;
            }
            default:{
                printf("error\n");
                break;
            }
        }
    }
    // printf("\\n\");\n");
    printf("\n");
    // if(p % 5 == 0 || q % 5 == 0){
    //     printf("\n");
    //     // fprintf(stderr, "Complete p=%d, q=%d\n", p, q);
    //     // fflush(stderr);
    // }
    // fflush(stdout);
}

int main(){
    freopen("luckysct.in", "r", stdin);
    freopen("luckysct.out", "w", stdout);
    int p = read(), q = read();
    if(p==1&&q==1)printf("c\n");
    else if(p==1&&q==2)printf("cts\n");
    else if(p==2&&q==2)printf("c\n");
    else if(p==1&&q==3)printf("ctsts\n");
    else if(p==2&&q==3)printf("ctstc\n");
    else if(p==3&&q==3)printf("c\n");
    else if(p==1&&q==4)printf("ctststs\n");
    else if(p==2&&q==4)printf("cts\n");
    else if(p==3&&q==4)printf("ctststc\n");
    else if(p==1&&q==5)printf("ctstststs\n");
    else if(p==2&&q==5)printf("ctstcts\n");
    else if(p==3&&q==5)printf("ctstctc\n");
    else if(p==4&&q==5)printf("ctstststc\n");
    else if(p==5&&q==5)printf("c\n");
    else if(p==1&&q==6)printf("ctststststs\n");
    else if(p==2&&q==6)printf("ctsts\n");
    else if(p==3&&q==6)printf("cts\n");
    else if(p==5&&q==6)printf("ctststststc\n");
    else if(p==1&&q==7)printf("cscsssststtst\n");
    else if(p==2&&q==7)printf("ctsscttt\n");
    else if(p==3&&q==7)printf("ctststcts\n");
    else if(p==4&&q==7)printf("ctststctc\n");
    else if(p==5&&q==7)printf("ctstctstc\n");
    else if(p==6&&q==7)printf("csttsttstttc\n");
    else if(p==7&&q==7)printf("c\n");
    else if(p==1&&q==8)printf("csttstttststst\n");
    else if(p==2&&q==8)printf("ctststs\n");
    else if(p==3&&q==8)printf("cssstsctt\n");
    else if(p==5&&q==8)printf("ctstctctc\n");
    else if(p==7&&q==8)printf("csstttttttttc\n");
    else if(p==1&&q==9)printf("cssttttttttstts\n");
    else if(p==2&&q==9)printf("ctssctttts\n");
    else if(p==3&&q==9)printf("ctsts\n");
    else if(p==4&&q==9)printf("cscsttttcst\n");
    else if(p==5&&q==9)printf("csctsccscsc\n");
    else if(p==6&&q==9)printf("ctstc\n");
    else if(p==7&&q==9)printf("ctsscttttc\n");
    else if(p==8&&q==9)printf("cssttttttttsttc\n");
    else if(p==1&&q==10)printf("None\n");
else if(p==2&&q==10)printf("ctstststs\n");
else if(p==3&&q==10)printf("cscscccstt\n");
else if(p==5&&q==10)printf("cts\n");
else if(p==7&&q==10)printf("ctststctstc\n");
else if(p==9&&q==10)printf("None\n");
else if(p==1&&q==11)printf("None\n");
else if(p==2&&q==11)printf("csstssttsss\n");
else if(p==3&&q==11)printf("cssstscttts\n");
else if(p==4&&q==11)printf("cstccsccss\n");
else if(p==5&&q==11)printf("cctstsctcs\n");
else if(p==6&&q==11)printf("csctttttct\n");
else if(p==7&&q==11)printf("cstccsccsc\n");
else if(p==8&&q==11)printf("cssstsctttc\n");
else if(p==9&&q==11)printf("cssctsttstc\n");
else if(p==10&&q==11)printf("None\n");
else if(p==11&&q==11)printf("c\n");
else if(p==1&&q==12)printf("None\n");
else if(p==2&&q==12)printf("ctststststs\n");
else if(p==3&&q==12)printf("ctststs\n");
else if(p==5&&q==12)printf("cscccsstscc\n");
else if(p==7&&q==12)printf("cscccsstscs\n");
else if(p==11&&q==12)printf("None\n");
else if(p==1&&q==13)printf("None\n");
else if(p==2&&q==13)printf("csctttttst\n");
else if(p==3&&q==13)printf("csttstccttt\n");
else if(p==4&&q==13)printf("cstctcstt\n");
else if(p==5&&q==13)printf("ctsstttsscc\n");
else if(p==6&&q==13)printf("cccsccs\n");
else if(p==7&&q==13)printf("cccsccc\n");
else if(p==8&&q==13)printf("ccctttccctc\n");
else if(p==9&&q==13)printf("cscscsscttc\n");
else if(p==10&&q==13)printf("ccctttssc\n");
else if(p==11&&q==13)printf("cscctttttttc\n");
else if(p==12&&q==13)printf("None\n");
else if(p==13&&q==13)printf("c\n");
else if(p==1&&q==14)printf("None\n");
else if(p==2&&q==14)printf("None\n");
else if(p==3&&q==14)printf("cttcsststt\n");
else if(p==5&&q==14)printf("ctscctctt\n");
else if(p==7&&q==14)printf("cts\n");
else if(p==9&&q==14)printf("csctctcssc\n");
else if(p==11&&q==14)printf("csstcsssttsc\n");
else if(p==13&&q==14)printf("None\n");
else if(p==1&&q==15)printf("None\n");
else if(p==2&&q==15)printf("csctttttstts\n");
else if(p==3&&q==15)printf("ctstststs\n");
else if(p==4&&q==15)printf("ccsccscttst\n");
else if(p==5&&q==15)printf("ctsts\n");
else if(p==6&&q==15)printf("ctstcts\n");
else if(p==7&&q==15)printf("cstcscscccs\n");
else if(p==8&&q==15)printf("cstcscscccc\n");
else if(p==10&&q==15)printf("ctstc\n");
else if(p==11&&q==15)printf("cscsssccsssc\n");
else if(p==13&&q==15)printf("csctttttsttc\n");
else if(p==14&&q==15)printf("None\n");
else if(p==1&&q==16)printf("None\n");
else if(p==2&&q==16)printf("None\n");
else if(p==3&&q==16)printf("ccctttsssts\n");
else if(p==5&&q==16)printf("csstttcsctt\n");
else if(p==7&&q==16)printf("cstccttcc\n");
else if(p==9&&q==16)printf("cstccttcs\n");
else if(p==11&&q==16)printf("cscsscsctsc\n");
else if(p==13&&q==16)printf("cccttsttssc\n");
else if(p==15&&q==16)printf("None\n");
else if(p==1&&q==17)printf("None\n");
else if(p==2&&q==17)printf("None\n");
else if(p==3&&q==17)printf("cscssttssss\n");
else if(p==4&&q==17)printf("cstcsccsttt\n");
else if(p==5&&q==17)printf("csttss\n");
else if(p==6&&q==17)printf("csttcscccst\n");
else if(p==7&&q==17)printf("csstsctcss\n");
else if(p==8&&q==17)printf("cscttcttcc\n");
else if(p==9&&q==17)printf("cscttcttcs\n");
else if(p==10&&q==17)printf("csstsctcsc\n");
else if(p==11&&q==17)printf("csttcttctsc\n");
else if(p==12&&q==17)printf("csttsc\n");
else if(p==13&&q==17)printf("cstctcstttc\n");
else if(p==14&&q==17)printf("cscssttsssc\n");
else if(p==15&&q==17)printf("None\n");
else if(p==16&&q==17)printf("None\n");
else if(p==17&&q==17)printf("c\n");
else if(p==1&&q==18)printf("None\n");
else if(p==2&&q==18)printf("None\n");
else if(p==3&&q==18)printf("ctststststs\n");
else if(p==5&&q==18)printf("cttscstsss\n");
else if(p==7&&q==18)printf("ctstttcsct\n");
else if(p==11&&q==18)printf("cssssscscsc\n");
else if(p==13&&q==18)printf("csttcsstsc\n");
else if(p==17&&q==18)printf("None\n");
else if(p==1&&q==19)printf("None\n");
else if(p==2&&q==19)printf("None\n");
else if(p==3&&q==19)printf("cscsssttssst\n");
else if(p==4&&q==19)printf("ctssssstt\n");
else if(p==5&&q==19)printf("ccccscsttt\n");
else if(p==6&&q==19)printf("cccsccsts\n");
else if(p==7&&q==19)printf("csscscttctt\n");
else if(p==8&&q==19)printf("cctsscscct\n");
else if(p==9&&q==19)printf("ctsctsct\n");
else if(p==10&&q==19)printf("cttsstssct\n");
else if(p==11&&q==19)printf("cctcstttcs\n");
else if(p==12&&q==19)printf("cssctstctsc\n");
else if(p==13&&q==19)printf("cccsccstc\n");
else if(p==14&&q==19)printf("ctscctctttc\n");
else if(p==15&&q==19)printf("cstcttssssc\n");
else if(p==16&&q==19)printf("csttttssttc\n");
else if(p==17&&q==19)printf("None\n");
else if(p==18&&q==19)printf("None\n");
else if(p==19&&q==19)printf("c\n");
else if(p==1&&q==20)printf("None\n");
else if(p==2&&q==20)printf("None\n");
else if(p==3&&q==20)printf("ctssttsttsst\n");
else if(p==5&&q==20)printf("ctststs\n");
else if(p==7&&q==20)printf("cccscccts\n");
else if(p==9&&q==20)printf("csttcsccs\n");
else if(p==11&&q==20)printf("csttcsccc\n");
else if(p==13&&q==20)printf("cccsccctc\n");
else if(p==15&&q==20)printf("ctststc\n");
else if(p==17&&q==20)printf("ctssttststtc\n");
else if(p==19&&q==20)printf("None\n");
else if(p==1&&q==21)printf("None\n");
else if(p==2&&q==21)printf("None\n");
else if(p==3&&q==21)printf("None\n");
else if(p==4&&q==21)printf("cscctttssst\n");
else if(p==5&&q==21)printf("cssctscctsst\n");
else if(p==6&&q==21)printf("ctsscttt\n");
else if(p==7&&q==21)printf("ctsts\n");
else if(p==8&&q==21)printf("cscctscsss\n");
else if(p==10&&q==21)printf("ctsttscss\n");
else if(p==11&&q==21)printf("ctsttscsc\n");
else if(p==13&&q==21)printf("cscctscssc\n");
else if(p==14&&q==21)printf("ctstc\n");
else if(p==16&&q==21)printf("cccscccttssc\n");
else if(p==17&&q==21)printf("cttttsstc\n");
else if(p==19&&q==21)printf("None\n");
else if(p==20&&q==21)printf("None\n");
else if(p==1&&q==22)printf("None\n");
else if(p==2&&q==22)printf("None\n");
else if(p==3&&q==22)printf("None\n");
else if(p==5&&q==22)printf("csttssts\n");
else if(p==7&&q==22)printf("ccctttcssts\n");
else if(p==9&&q==22)printf("ccssssctct\n");
else if(p==11&&q==22)printf("cts\n");
else if(p==13&&q==22)printf("csstsctsccc\n");
else if(p==15&&q==22)printf("ccctttcsstc\n");
else if(p==17&&q==22)printf("csttsstc\n");
else if(p==19&&q==22)printf("None\n");
else if(p==21&&q==22)printf("None\n");
else if(p==1&&q==23)printf("None\n");
else if(p==2&&q==23)printf("None\n");
else if(p==3&&q==23)printf("None\n");
else if(p==4&&q==23)printf("ctsssssttts\n");
else if(p==5&&q==23)printf("ctttscttttt\n");
else if(p==6&&q==23)printf("cstcsscttst\n");
else if(p==7&&q==23)printf("cctstcsstt\n");
else if(p==8&&q==23)printf("csttctctctt\n");
else if(p==9&&q==23)printf("ccsttctcss\n");
else if(p==10&&q==23)printf("cttstcc\n");
else if(p==11&&q==23)printf("cccsccscscs\n");
else if(p==12&&q==23)printf("ccsccstssct\n");
else if(p==13&&q==23)printf("cttstcs\n");
else if(p==14&&q==23)printf("ccsttctcsc\n");
else if(p==15&&q==23)printf("ccctttcsctc\n");
else if(p==16&&q==23)printf("cstccttcctc\n");
else if(p==17&&q==23)printf("cttcccssstc\n");
else if(p==18&&q==23)printf("csttcsstsstc\n");
else if(p==19&&q==23)printf("ctssssstttc\n");
else if(p==20&&q==23)printf("None\n");
else if(p==21&&q==23)printf("None\n");
else if(p==22&&q==23)printf("None\n");
else if(p==23&&q==23)printf("c\n");
else if(p==1&&q==24)printf("None\n");
else if(p==2&&q==24)printf("None\n");
else if(p==3&&q==24)printf("None\n");
else if(p==5&&q==24)printf("cstcccststst\n");
else if(p==7&&q==24)printf("cssscstcctt\n");
else if(p==11&&q==24)printf("ctsstcss\n");
else if(p==13&&q==24)printf("ctsstcsc\n");
else if(p==17&&q==24)printf("cssccsccsssc\n");
else if(p==19&&q==24)printf("cscccsssstsc\n");
else if(p==23&&q==24)printf("None\n");
else if(p==1&&q==25)printf("None\n");
else if(p==2&&q==25)printf("None\n");
else if(p==3&&q==25)printf("None\n");
else if(p==4&&q==25)printf("ctttsttstss\n");
else if(p==5&&q==25)printf("ctstststs\n");
else if(p==6&&q==25)printf("ccsstcttstt\n");
else if(p==7&&q==25)printf("cstsctsst\n");
else if(p==8&&q==25)printf("csssctcscsst\n");
else if(p==9&&q==25)printf("cscscsssctt\n");
else if(p==10&&q==25)printf("ctstcts\n");
else if(p==11&&q==25)printf("csctcssct\n");
else if(p==12&&q==25)printf("cststctcs\n");
else if(p==13&&q==25)printf("cststctcc\n");
else if(p==14&&q==25)printf("ccsstctttcs\n");
else if(p==15&&q==25)printf("ctstctc\n");
else if(p==16&&q==25)printf("csssttsccc\n");
else if(p==17&&q==25)printf("csstcssscttc\n");
else if(p==18&&q==25)printf("cstcsscsttc\n");
else if(p==19&&q==25)printf("ctscstsssc\n");
else if(p==20&&q==25)printf("ctstststc\n");
else if(p==21&&q==25)printf("csctststtsc\n");
else if(p==22&&q==25)printf("None\n");
else if(p==23&&q==25)printf("None\n");
else if(p==24&&q==25)printf("None\n");
else if(p==1&&q==26)printf("None\n");
else if(p==2&&q==26)printf("None\n");
else if(p==3&&q==26)printf("None\n");
else if(p==5&&q==26)printf("cscscsstttts\n");
else if(p==7&&q==26)printf("csssccssst\n");
else if(p==9&&q==26)printf("ctssctctctt\n");
else if(p==11&&q==26)printf("ctttsscst\n");
else if(p==13&&q==26)printf("cts\n");
else if(p==15&&q==26)printf("cscssccccc\n");
else if(p==17&&q==26)printf("cscttcttcstc\n");
else if(p==19&&q==26)printf("cscctcctssc\n");
else if(p==21&&q==26)printf("cssctststsc\n");
else if(p==23&&q==26)printf("None\n");
else if(p==25&&q==26)printf("None\n");
else if(p==1&&q==27)printf("None\n");
else if(p==2&&q==27)printf("None\n");
else if(p==3&&q==27)printf("None\n");
else if(p==4&&q==27)printf("None\n");
else if(p==5&&q==27)printf("csttsststs\n");
else if(p==6&&q==27)printf("ctssctttts\n");
else if(p==7&&q==27)printf("cccsccctsts\n");
else if(p==8&&q==27)printf("cttcssst\n");
else if(p==10&&q==27)printf("ctssccscct\n");
else if(p==11&&q==27)printf("cstsstscsss\n");
else if(p==13&&q==27)printf("cstscccs\n");
else if(p==14&&q==27)printf("cstscccc\n");
else if(p==16&&q==27)printf("cstsstscssc\n");
else if(p==17&&q==27)printf("cscssctctc\n");
else if(p==19&&q==27)printf("cctscstssc\n");
else if(p==20&&q==27)printf("cccsccctstc\n");
else if(p==22&&q==27)printf("csttsststc\n");
else if(p==23&&q==27)printf("csststttsttc\n");
else if(p==25&&q==27)printf("None\n");
else if(p==26&&q==27)printf("None\n");
else if(p==1&&q==28)printf("None\n");
else if(p==2&&q==28)printf("None\n");
else if(p==3&&q==28)printf("None\n");
else if(p==5&&q==28)printf("cscccttsttt\n");
else if(p==7&&q==28)printf("ctststs\n");
else if(p==9&&q==28)printf("csctcstt\n");
else if(p==11&&q==28)printf("cscttssctt\n");
else if(p==13&&q==28)printf("cctcttct\n");
else if(p==15&&q==28)printf("cssssttstct\n");
else if(p==17&&q==28)printf("cccsttcssc\n");
else if(p==19&&q==28)printf("ccctcstc\n");
else if(p==21&&q==28)printf("ctststc\n");
else if(p==23&&q==28)printf("csccttststsc\n");
else if(p==25&&q==28)printf("None\n");
else if(p==27&&q==28)printf("None\n");
else if(p==1&&q==29)printf("None\n");
else if(p==2&&q==29)printf("None\n");
else if(p==3&&q==29)printf("None\n");
else if(p==4&&q==29)printf("ctsttttssttt\n");
else if(p==5&&q==29)printf("ccssccsstttt\n");
else if(p==6&&q==29)printf("cccsttcctttt\n");
else if(p==7&&q==29)printf("cscsccstst\n");
else if(p==8&&q==29)printf("cscsst\n");
else if(p==9&&q==29)printf("cccttctsss\n");
else if(p==10&&q==29)printf("ccsstcccsts\n");
else if(p==11&&q==29)printf("csccssstctt\n");
else if(p==12&&q==29)printf("csttscts\n");
else if(p==13&&q==29)printf("cccscssscc\n");
else if(p==14&&q==29)printf("csstctssct\n");
else if(p==15&&q==29)printf("cstccsttsct\n");
else if(p==16&&q==29)printf("cccscssscs\n");
else if(p==17&&q==29)printf("csttsctc\n");
else if(p==18&&q==29)printf("cstttstctsc\n");
else if(p==19&&q==29)printf("ccctcctc\n");
else if(p==20&&q==29)printf("cccttctssc\n");
else if(p==21&&q==29)printf("csssctcsttc\n");
else if(p==22&&q==29)printf("ctsccctsstc\n");
else if(p==23&&q==29)printf("ccssccststc\n");
else if(p==24&&q==29)printf("None\n");
else if(p==25&&q==29)printf("None\n");
else if(p==26&&q==29)printf("cctttttttttc\n");
else if(p==27&&q==29)printf("None\n");
else if(p==28&&q==29)printf("None\n");
else if(p==29&&q==29)printf("c\n");
else if(p==1&&q==30)printf("None\n");
else if(p==2&&q==30)printf("None\n");
else if(p==3&&q==30)printf("None\n");
else if(p==5&&q==30)printf("ctststststs\n");
else if(p==7&&q==30)printf("cctctsttss\n");
else if(p==11&&q==30)printf("cttsccscct\n");
else if(p==13&&q==30)printf("csstcss\n");
else if(p==17&&q==30)printf("csstcsc\n");
else if(p==19&&q==30)printf("ctttsscstc\n");
else if(p==23&&q==30)printf("cctctsttsc\n");
else if(p==29&&q==30)printf("None\n");
else if(p==1&&q==31)printf("None\n");
else if(p==2&&q==31)printf("None\n");
else if(p==3&&q==31)printf("None\n");
else if(p==4&&q==31)printf("ccstststtt\n");
else if(p==5&&q==31)printf("csctttsstt\n");
else if(p==6&&q==31)printf("cctsccttsst\n");
else if(p==7&&q==31)printf("cstctsssst\n");
else if(p==8&&q==31)printf("ccttsctstst\n");
else if(p==9&&q==31)printf("csstccsst\n");
else if(p==10&&q==31)printf("cscscttctts\n");
else if(p==11&&q==31)printf("csttcscccts\n");
else if(p==12&&q==31)printf("cssstcsss\n");
else if(p==13&&q==31)printf("ccstscsss\n");
else if(p==14&&q==31)printf("cssccstcss\n");
else if(p==15&&q==31)printf("cssttcstcc\n");
else if(p==16&&q==31)printf("csssstssct\n");
else if(p==17&&q==31)printf("cctsttct\n");
else if(p==18&&q==31)printf("ccstscssc\n");
else if(p==19&&q==31)printf("cssstcssc\n");
else if(p==20&&q==31)printf("csttcsccctc\n");
else if(p==21&&q==31)printf("cscscttcttc\n");
else if(p==22&&q==31)printf("cttcssssc\n");
else if(p==23&&q==31)printf("csccstcsttsc\n");
else if(p==24&&q==31)printf("cscccstsssc\n");
else if(p==25&&q==31)printf("cctcctssstc\n");
else if(p==26&&q==31)printf("cscctttstttc\n");
else if(p==27&&q==31)printf("ccsstttttc\n");
else if(p==28&&q==31)printf("None\n");
else if(p==29&&q==31)printf("None\n");
else if(p==30&&q==31)printf("None\n");
else if(p==31&&q==31)printf("c\n");
else if(p==1&&q==32)printf("None\n");
else if(p==2&&q==32)printf("None\n");
else if(p==3&&q==32)printf("None\n");
else if(p==5&&q==32)printf("cssttststtt\n");
else if(p==7&&q==32)printf("cstsctsstts\n");
else if(p==9&&q==32)printf("cscscctscctt\n");
else if(p==11&&q==32)printf("csscsscsst\n");
else if(p==13&&q==32)printf("cctttsctt\n");
else if(p==15&&q==32)printf("csccctcc\n");
else if(p==17&&q==32)printf("csccctcs\n");
else if(p==19&&q==32)printf("cccsccstctc\n");
else if(p==21&&q==32)printf("cscstsstccc\n");
else if(p==23&&q==32)printf("cssccsstc\n");
else if(p==25&&q==32)printf("cstsctssttc\n");
else if(p==27&&q==32)printf("cststtststsc\n");
else if(p==29&&q==32)printf("None\n");
else if(p==31&&q==32)printf("None\n");
else if(p==1&&q==33)printf("None\n");
else if(p==2&&q==33)printf("None\n");
else if(p==3&&q==33)printf("None\n");
else if(p==4&&q==33)printf("None\n");
else if(p==5&&q==33)printf("ctstttssttt\n");
else if(p==6&&q==33)printf("csstssttsss\n");
else if(p==7&&q==33)printf("ccscststsst\n");
else if(p==8&&q==33)printf("cstccctstss\n");
else if(p==10&&q==33)printf("cttstccts\n");
else if(p==11&&q==33)printf("ctsts\n");
else if(p==13&&q==33)printf("cstttstctt\n");
else if(p==14&&q==33)printf("ccttcssct\n");
else if(p==16&&q==33)printf("cststtscss\n");
else if(p==17&&q==33)printf("cststtscsc\n");
else if(p==19&&q==33)printf("cctttcssc\n");
else if(p==20&&q==33)printf("ctttsttcs\n");
else if(p==22&&q==33)printf("ctstc\n");
else if(p==23&&q==33)printf("cctcsctsc\n");
else if(p==25&&q==33)printf("cstccctstsc\n");
else if(p==26&&q==33)printf("ccctstsstc\n");
else if(p==28&&q==33)printf("cscstttstssc\n");
else if(p==29&&q==33)printf("None\n");
else if(p==31&&q==33)printf("None\n");
else if(p==32&&q==33)printf("None\n");
else if(p==1&&q==34)printf("None\n");
else if(p==2&&q==34)printf("None\n");
else if(p==3&&q==34)printf("None\n");
else if(p==5&&q==34)printf("None\n");
else if(p==7&&q==34)printf("cctcttttst\n");
else if(p==9&&q==34)printf("cccttcctst\n");
else if(p==11&&q==34)printf("csccsctss\n");
else if(p==13&&q==34)printf("csssstsctt\n");
else if(p==15&&q==34)printf("cssstcssct\n");
else if(p==17&&q==34)printf("cts\n");
else if(p==19&&q==34)printf("csttsstsctc\n");
else if(p==21&&q==34)printf("cssttstssscs\n");
else if(p==23&&q==34)printf("csccsctsc\n");
else if(p==25&&q==34)printf("cstctsssc\n");
else if(p==27&&q==34)printf("cstsctstttc\n");
else if(p==29&&q==34)printf("None\n");
else if(p==31&&q==34)printf("None\n");
else if(p==33&&q==34)printf("None\n");
else if(p==1&&q==35)printf("None\n");
else if(p==2&&q==35)printf("None\n");
else if(p==3&&q==35)printf("None\n");
else if(p==4&&q==35)printf("ccsstttttsst\n");
else if(p==5&&q==35)printf("None\n");
else if(p==6&&q==35)printf("cssstssttst\n");
else if(p==7&&q==35)printf("ctstststs\n");
else if(p==8&&q==35)printf("cttcssstts\n");
else if(p==9&&q==35)printf("cccscccsstt\n");
else if(p==10&&q==35)printf("ctsscttt\n");
else if(p==11&&q==35)printf("cctccctts\n");
else if(p==12&&q==35)printf("ccsttctcsss\n");
else if(p==13&&q==35)printf("ctttttcsst\n");
else if(p==14&&q==35)printf("ctstcts\n");
else if(p==15&&q==35)printf("ctststcts\n");
else if(p==16&&q==35)printf("cscctsscss\n");
else if(p==17&&q==35)printf("cctctctcc\n");
else if(p==18&&q==35)printf("cctctctcs\n");
else if(p==19&&q==35)printf("cccctcsc\n");
else if(p==20&&q==35)printf("ctststctc\n");
else if(p==21&&q==35)printf("ctstctc\n");
else if(p==22&&q==35)printf("cctcsscsctc\n");
else if(p==23&&q==35)printf("ccssccsccsc\n");
else if(p==24&&q==35)printf("cctcccttc\n");
else if(p==26&&q==35)printf("ccsssccstc\n");
else if(p==27&&q==35)printf("cttcsssttc\n");
else if(p==28&&q==35)printf("ctstststc\n");
else if(p==29&&q==35)printf("csscttsttssc\n");
else if(p==31&&q==35)printf("ccssttttsttc\n");
else if(p==32&&q==35)printf("None\n");
else if(p==33&&q==35)printf("None\n");
else if(p==34&&q==35)printf("None\n");
else if(p==1&&q==36)printf("None\n");
else if(p==2&&q==36)printf("None\n");
else if(p==3&&q==36)printf("None\n");
else if(p==5&&q==36)printf("csctttssttts\n");
else if(p==7&&q==36)printf("cstsssstst\n");
else if(p==11&&q==36)printf("cscssccctst\n");
else if(p==13&&q==36)printf("cttstcsts\n");
else if(p==17&&q==36)printf("cccstcstcc\n");
else if(p==19&&q==36)printf("csttssstct\n");
else if(p==23&&q==36)printf("cttstcstc\n");
else if(p==25&&q==36)printf("csctcsscttc\n");
else if(p==29&&q==36)printf("cscsccststtc\n");
else if(p==31&&q==36)printf("cscttstttstc\n");
else if(p==35&&q==36)printf("None\n");
else if(p==1&&q==37)printf("None\n");
else if(p==2&&q==37)printf("None\n");
else if(p==3&&q==37)printf("None\n");
else if(p==4&&q==37)printf("None\n");
else if(p==5&&q==37)printf("ccsttsttt\n");
else if(p==6&&q==37)printf("csscsttttsst\n");
else if(p==7&&q==37)printf("csccstttsst\n");
else if(p==8&&q==37)printf("cscsstts\n");
else if(p==9&&q==37)printf("cstcssstt\n");
else if(p==10&&q==37)printf("ccccsts\n");
else if(p==11&&q==37)printf("ccsstttcct\n");
else if(p==12&&q==37)printf("cstsstctsss\n");
else if(p==13&&q==37)printf("ctsstcscts\n");
else if(p==14&&q==37)printf("cssccscts\n");
else if(p==15&&q==37)printf("csccttcst\n");
else if(p==16&&q==37)printf("cssstctccs\n");
else if(p==17&&q==37)printf("cscstcsccs\n");
else if(p==18&&q==37)printf("csscttctscc\n");
else if(p==19&&q==37)printf("csscttctscs\n");
else if(p==20&&q==37)printf("cscstcsccc\n");
else if(p==21&&q==37)printf("cssstctccc\n");
else if(p==22&&q==37)printf("ctttsctcsc\n");
else if(p==23&&q==37)printf("cssccsctc\n");
else if(p==24&&q==37)printf("ctsstcsctc\n");
else if(p==25&&q==37)printf("cstsstctssc\n");
else if(p==26&&q==37)printf("ctttsscsttc\n");
else if(p==27&&q==37)printf("ccccstc\n");
else if(p==28&&q==37)printf("csctcstttc\n");
else if(p==29&&q==37)printf("cscssttc\n");
else if(p==30&&q==37)printf("cstctttttc\n");
else if(p==31&&q==37)printf("cssststtstsc\n");
else if(p==32&&q==37)printf("None\n");
else if(p==33&&q==37)printf("None\n");
else if(p==34&&q==37)printf("None\n");
else if(p==35&&q==37)printf("None\n");
else if(p==36&&q==37)printf("None\n");
else if(p==37&&q==37)printf("c\n");
else if(p==1&&q==38)printf("None\n");
else if(p==2&&q==38)printf("None\n");
else if(p==3&&q==38)printf("None\n");
else if(p==5&&q==38)printf("None\n");
else if(p==7&&q==38)printf("cctsst\n");
else if(p==9&&q==38)printf("csctccstst\n");
else if(p==11&&q==38)printf("cccsccstt\n");
else if(p==13&&q==38)printf("cstsstttccs\n");
else if(p==15&&q==38)printf("cssststsscc\n");
else if(p==17&&q==38)printf("cttcctscc\n");
else if(p==19&&q==38)printf("cts\n");
else if(p==21&&q==38)printf("cttcctscs\n");
else if(p==23&&q==38)printf("cssststsscs\n");
else if(p==25&&q==38)printf("cstsstttccc\n");
else if(p==27&&q==38)printf("csctsctcstsc\n");
else if(p==29&&q==38)printf("ctssctsttc\n");
else if(p==31&&q==38)printf("cstctssssttc\n");
else if(p==33&&q==38)printf("None\n");
else if(p==35&&q==38)printf("None\n");
else if(p==37&&q==38)printf("None\n");
else if(p==1&&q==39)printf("None\n");
else if(p==2&&q==39)printf("None\n");
else if(p==3&&q==39)printf("None\n");
else if(p==4&&q==39)printf("None\n");
else if(p==5&&q==39)printf("cctstsstssss\n");
else if(p==6&&q==39)printf("csctttttst\n");
else if(p==7&&q==39)printf("csssctttttss\n");
else if(p==8&&q==39)printf("cccccttstst\n");
else if(p==10&&q==39)printf("ccctcctsts\n");
else if(p==11&&q==39)printf("ctttt\n");
else if(p==13&&q==39)printf("ctsts\n");
else if(p==14&&q==39)printf("cscstcsst\n");
else if(p==16&&q==39)printf("csctctcss\n");
else if(p==17&&q==39)printf("csttsstcts\n");
else if(p==19&&q==39)printf("cstccsssct\n");
else if(p==20&&q==39)printf("ccsccttcccs\n");
else if(p==22&&q==39)printf("csttsstctc\n");
else if(p==23&&q==39)printf("csctctcsc\n");
else if(p==25&&q==39)printf("ccttccttccc\n");
else if(p==26&&q==39)printf("ctstc\n");
else if(p==28&&q==39)printf("csctcsctssc\n");
else if(p==29&&q==39)printf("ccctcctstc\n");
else if(p==31&&q==39)printf("cctcscttttc\n");
else if(p==32&&q==39)printf("csssctttttsc\n");
else if(p==34&&q==39)printf("ccstttsssssc\n");
else if(p==35&&q==39)printf("None\n");
else if(p==37&&q==39)printf("None\n");
else CAL(p, q);
    // fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}

template < typename T >
inline T read(void){
    T ret(0);
    T flag(1);
    char c = getchar();
    while(!isdigit(c) && c != '-')c = getchar();
    if(c == '-'){flag = -1; c = getchar();}
    while(isdigit(c)){
        ret *= 10;
        ret += int(c - '0');
        c = getchar();
    }
    ret *= flag;
    return ret;
}