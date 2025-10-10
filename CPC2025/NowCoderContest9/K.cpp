#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;

template<typename T = int>
inline T read(void);

struct Rope{
    int x, y;
    int l2;
};

vector < Rope > rops;

int N;
const double INF = 999114514.0;
const double EPS = 1.14514e-12;

const int TOT_SEEDS = 0;

int main(){
    N = read();

    vector < pair < double, double > > seeds;
    seeds.push_back({0, 0});

    int totx(0), toty(0);

    for(int i = 1; i <= N; ++i){
        int x = read(), y = read(), l2 = read();
        rops.push_back(Rope{x, y, l2});
        // seeds.push_back({(double)x, (double)y});
        // if(rndd(1, 100) <= 1)seeds.push_back({(double)x, (double)y});
        totx += x, toty += y;
    }

    seeds.push_back({(double)totx / N, (double)toty / N});
    
    auto CalZ2 = [](double x, double y, int* idx = nullptr)->double{
        double ret(INF);
        int curidx(0);
        for(auto [xi, yi, l2] : rops){
            double val = (double)l2 - (x - xi) * (x - xi) - (y - yi) * (y - yi);
            if(val < ret){
                ret = val;
                if(idx)*idx = curidx;
            }++curidx;
        }return ret;
    };
    // auto FastCalZ2 = [&](double x, double y, double lim, bool &failed)->double{
    //     double ret = INF;
    //     int curidx(0);
    //     failed = false;
    //     for(auto [xi, yi, l2] : rops){
    //         double val = (double)l2 - (x - xi) * (x - xi) - (y - yi) * (y - yi);
    //         if(val < ret){
    //             ret = val;
    //             if(ret <= lim)return failed = true, ret;
    //         }++curidx;
    //     }return ret;
    // };


    seeds.push_back({-128.0, -128.0});
    seeds.push_back({-128.0, 128.0});
    seeds.push_back({128.0, -128.0});
    seeds.push_back({128.0, 128.0});

    for(int i = 1; i <= TOT_SEEDS; ++i)
        seeds.push_back({rndd(-128, 128), rndd(-128, 128)});

    // seeds.push_back({-0.166666667, -0.166666667});

    // double bestX = 0.0, bestY = 0.0;
    // double bestZ2 = -INF;

    // auto SimulateAnneal = [&]()->void{
    //     uniform_real_distribution < double > U(0.0, 1.0);
    //     auto rnd01 = [&]()->double{return U(rnd);};
    //     auto rndStep = [&](double T)->double{return (rnd01() * 2.0 - 1.0) * T;};
    //     const double T0 = 64.0;
    //     const double TMIN = 1e-4;
    //     const double COOL = 0.90;
    //     const int TOT_ATTEMPS = 10;

    //     for(auto [sx, sy] : seeds){
    //         double x = sx, y = sy;
    //         double cur = CalZ2(x, y);
    //         double T = T0;

    //         while(T > TMIN){
    //             for(int curT = 0; curT < TOT_ATTEMPS; ++curT){
    //                 double tx = x + rndStep(T);
    //                 double ty = y + rndStep(T);
            
    //                 if(tx < -128.0)tx = -128.0;
    //                 if(tx > 128.0)tx =  128.0;
    //                 if(ty < -128.0)ty = -128.0;
    //                 if(ty > 128.0)ty =  128.0;

    //                 double val = rnd01();
    //                 val = val < 1e-114 ? 1e-114 : val;
    //                 double lim = cur + T * log(val);

    //                 bool flag(false);
    //                 double nxt = FastCalZ2(tx, ty, lim, flag);

    //                 if(!flag && (nxt >= cur || nxt > lim))
    //                     x = tx, y = ty, cur = nxt;
                        

    //                 double txt = CalZ2(tx, ty);
    //                 double delta = txt - cur;
    //                 if(delta >= 0.0 || exp(delta / max(EPS, T)) > rnd01()){
    //                     x = tx; y = ty; cur = txt;
    //                 }
    //             }
    //             T *= COOL;
    //         }

        
    //     }

    // }; SimulateAnneal();

    auto Climb = [&](double sx, double tx)->tuple < double, double, double >{
        // printf("Make Climb.\n"); fflush(stdout);
        double x = sx, y = tx;
        double hv = CalZ2(x, y);
        double step = 64.0;            
        const double SHRINK_RATE = 0.55;
        const double EPS_STEP = 1e-12;
        const int TOT_ATTEMPS = 10;
        while(step > EPS_STEP){
            // if((double)clock() / CLOCKS_PER_SEC > 1.5)break;
            bool better(false);
            for(int t = 0; t < TOT_ATTEMPS; ++t) {
                int k; double m = CalZ2(x, y, &k); 
                double tx = rops[k].x - x, ty = rops[k].y - y;
                double val = hypot(tx, ty);
                if(val < 1e-18)tx = 1.0, ty = 0.0, val = 1.0;
                tx /= val; ty /= val;
                double curx = x + tx * step;
                double cury = y + ty * step;
                double curv = CalZ2(curx, cury, nullptr);
                if (curv > hv){x = curx, y = cury, hv = curv; better = true; break; }
                double angs[4] = {M_PI * 0.25, -M_PI * 0.25, M_PI * 0.5, -M_PI * 0.5};
                bool success(false);
                for(auto ang : angs){
                    double cosv = cos(ang), sinv = sin(ang);
                    double tx2 = tx * cosv - ty * sinv, ty2 = tx * sinv + ty * cosv;
                    curx = x + tx2 * step; cury = y + ty2 * step;
                    curv = CalZ2(curx, cury);
                    if(curv > hv){x = curx, y = cury, hv = curv, better = true, success = true; break;}
                }
                if(success)break;
            }
            if(!better)step *= SHRINK_RATE;
        }return {x, y, hv};
    };

    double bestZ2 = -INF, bestX = 0, bestY = 0;
    for(auto [sx, sy] : seeds){
        if((double)clock() / CLOCKS_PER_SEC > 1.5)break;
        auto [x, y, z2] = Climb(sx, sy);
        if(z2 > bestZ2){bestZ2 = z2; bestX = x; bestY = y;}
    }
    while((double)clock() / CLOCKS_PER_SEC < 1.5){
        int sx = rndd(-128, 128), sy = rndd(-128, 128);
        auto [x, y, z2] = Climb(sx, sy);
        if(z2 > bestZ2){bestZ2 = z2; bestX = x; bestY = y;}

    }

    double bestZ = -sqrt(bestZ2 < 0.0 ? 0.0 : bestZ2);

    printf("%.9lf %.9lf %.9lf\n", bestX, bestY, bestZ);




    

    


    // fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}



template<typename T>
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