#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("no-stack-protector")

#include <bits/stdc++.h>
#define int long long 
#define double long double
using namespace std;
const double eps=1e-7;
const int N=11;

int T,n,m,X,Y,per[N];
double ans,ansx[N],a[N],ff[N],aa[N],coeff[N];
struct qwq{
    double w,h;
}b[N],bb[N];

// ----------- 自适应 Simpson ------------
double f_arc(const double coeffs[], int degree, double x) {
    double result = 0.0;
    for (int i = 0; i < degree; ++i) {
        result = result * x + coeffs[i] * (degree - i);
    }
    double d = result;
    return sqrt(1.0 + d*d);
}

double simpson_segment(const double coeffs[], int degree, double l, double r) {
    double m = 0.5L*(l + r);
    return (f_arc(coeffs, degree, l)
          + 4.0L * f_arc(coeffs, degree, m)
          + f_arc(coeffs, degree, r))
         * (r - l) / 6.0L;
}

double adaptiveSimpson_rec(const double coeffs[], int degree,
                           double l, double r, double eps, double A) {
    double m = 0.5L*(l + r);
    double L = simpson_segment(coeffs, degree, l, m);
    double R = simpson_segment(coeffs, degree, m, r);
    if (fabs(L + R - A) < 15*eps) {
        return L + R + (L + R - A)/15.0L;
    }
    return adaptiveSimpson_rec(coeffs, degree, l, m, eps/2.0L, L)
         + adaptiveSimpson_rec(coeffs, degree, m, r, eps/2.0L, R);
}

double calculateArcLength(const double coeffs[], int degree, double x1, double x2) {
    if (fabsl(x1 - x2) < 1e-12) return 0.0;
    double l = x1, r = x2;
    if (l > r) swap(l,r);
    double A = simpson_segment(coeffs, degree, l, r);
    return adaptiveSimpson_rec(coeffs, degree, l, r, 1e-9L, A);
}
// ---------------------------------------

double evaluateDerivative(const double coeffs[], int degree, double x) {
    if (degree == 0) return 0.0;
    double result = 0.0;
    for (int i = 0; i < degree; ++i) {
        result = result * x + (coeffs[i] * (degree - i));
    }
    return result;
}

double evaluate(const double coeffs[], int degree, double x) {
    double result = 0.0;
    for (int i = 0; i <= degree; ++i) {
        result = result * x + coeffs[i];
    }
    return result;
}

const int MAX_ITERATIONS = 100;
const double TOLERANCE = 1e-7;

bool newtonRaphson(const double coeffs[], int degree, double& out_root) {
    vector<double> initial_guesses = {0.0, 1.0, -1.0, 10.0, -10.0};
    for (double guess : initial_guesses) {
        double x = guess;
        for (int i = 0; i < MAX_ITERATIONS; ++i) {
            double fx = evaluate(coeffs, degree, x);
            double fpx = evaluateDerivative(coeffs, degree, x);
            if (fabs(fpx) < TOLERANCE) break;
            double nx = x - fx / fpx;
            if (fabs(nx - x) < TOLERANCE) { x = nx; break; }
            x = nx;
        }
        if (fabs(evaluate(coeffs, degree, x)) < 1e-6L) {
            out_root = x;
            return true;
        }
    }
    return false;
}

vector<double> solveRealRoots(const double coeffs[], int degree) {
    if (degree == 1) {
        if (fabs(coeffs[0]) > TOLERANCE)
            return { -coeffs[1]/coeffs[0] };
        else return {};
    }
    if (degree == 2) {
        double A=coeffs[0], B=coeffs[1], C=coeffs[2];
        double D=B*B-4*A*C;
        if (D<0) return {};
        if (D==0) return { -B/(2*A) };
        return { (-B+sqrt(D))/(2*A), (-B-sqrt(D))/(2*A) };
    }
    vector<double> tmp(coeffs, coeffs+degree+1), roots;
    int cur=degree;
    while (cur>2) {
        double r;
        if (!newtonRaphson(tmp.data(), cur, r)) break;
        roots.push_back(r);
        for (int i = 1; i <= cur; ++i)
            tmp[i] += tmp[i-1] * r;
        tmp.pop_back(); --cur;
    }
    if (cur>0) {
        auto rem = solveRealRoots(tmp.data(), cur);
        roots.insert(roots.end(), rem.begin(), rem.end());
    }
    sort(roots.begin(), roots.end());
    roots.erase(unique(roots.begin(), roots.end(),
                [](double a,double b){ return fabs(a-b)<1e-7; }),
                roots.end());
    return roots;
}

double F(double x) {
    double xx=1, s=0;
    for (int i=1;i<=m;i++){ xx*=x; s+=a[i]*xx; }
    return s;
}

double oDis(double x1,double y1,double x2,double y2) {
    double dx=x2-x1, dy=y2-y1;
    return sqrt(dx*dx+dy*dy);
}

double dist(pair<double,double> now,double d) {
    double l=now.first, r=l+d;
    while (l+eps<r) {
        double m=(l+r)/2;
        if (oDis(now.first,now.second,m,F(m))<d) l=m;
        else r=m;
    }
    return l;
}

void output(double x){
    static char s[25];
    sprintf(s,"%.4Le",x);
    for(int i:{0,1,2,3,4,5,6,7}) printf("%c",s[i]);
    printf("%c",s[strlen(s)-1]);
}

bool cmpd(double a,double b){ return a<b; }

signed main(){
    scanf("%lld",&T);
    while (T--) {
        scanf("%lld%lld%lld%lld",&n,&m,&X,&Y);
        for (int i=1;i<=m;i++) scanf("%Lf",&a[i]);
        int cnt=-1;
        for (int i=m;i>=0;i--) aa[++cnt]=a[i];
        for (int i=1;i<=n;i++){
            scanf("%Lf%Lf",&bb[i].h,&bb[i].w);
            per[i]=i;
        }
        ans=1e18;
        do {
            for (int i=1;i<=n;i++) b[i]=bb[per[i]];
            double nowx=0, nowy;
            double lastX = 0;            // <<-- 新增：记录上一次的 x
            ansx[1]=0;
            for (int i=1;i<n;i++){
                double t1 = dist({nowx, F(nowx)}, max(b[i].h, b[i+1].h));
                nowy = F(nowx) + b[i].h;
                int tot = -1;
                for (int j=m;j>=2;j--) coeff[++tot]=a[j];
                double k = (Y - nowy)/(X - nowx);
                coeff[++tot] = a[1] - k;
                coeff[++tot] = -Y + k*X;
                auto roots = solveRealRoots(coeff, m);
                sort(roots.begin(), roots.end(), cmpd);
                double t2 = nowx;
                for (double r : roots) if (r > nowx + 1e-12) { t2 = r; break; }
                nowx = max(t1, t2);

                // <<-- 只积分 [lastX, nowx] 的增量
                double delta = calculateArcLength(aa, m, lastX, nowx);
                ansx[i+1] = ansx[i] + delta;
                lastX = nowx;
            }
            double sum=0;
            for (int i=1;i<=n;i++) sum += b[i].w * ansx[i];
            ans = min(ans, sum);
        } while (next_permutation(per+1, per+n+1));

        output(ans);
    }
    return 0;
}
