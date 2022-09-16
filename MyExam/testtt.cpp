#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
// #include"testlib.h"
using namespace std;
const double Pi=acos(-1.0);
const double EPS=1e-9;

FILE* fin;//标准输入
FILE* fout;//用户输出
FILE* fstd;//标准输出
FILE* fscore;//得分文件
FILE* freport;//报告文件
int perScore;

void quit(double x)
{
	fprintf(fscore,"%d\n", int(x*perScore+0.5));
	
	// if(type >= 0)
	// {
	// 	fprintf(freport, "Check Error at pos[%d]\n", type);
	// }
	// else switch(type)
	// {
	// 	case -1:
	// 		fprintf(freport, "Check Error!\n");
	// 		break;
	// 	case -2:
	// 		fprintf(freport, "strlen &gt; 2*Q!\n");
	// 		break;
	// 	case -3:
	// 		fprintf(freport, "P and Q calc Error!\n");
	// 		break;
	// 	default:
	// 		fprintf(freport, "Unkown Error!\n");
	// 		break;
	// }
	fclose(fin);
	fclose(fout);
	fclose(fstd);
	fclose(fscore);
	fclose(freport);
	exit(0);
}




int sign(double a){return a<-EPS?-1:a>EPS;}
int sign2(double a){return a<-1e-5?-1:a>1e-5;}
int cmp(double a,double b){return sign(a-b);}
int cmp2(double a,double b){return sign2(a-b);}
struct Point
{
	double x,y;
	Point(double xx=0,double yy=0){x=xx,y=yy;}
	Point operator+(Point p){return Point(x+p.x,y+p.y);}
	Point operator-(Point p){return Point(x-p.x,y-p.y);}
	Point operator*(double d){return Point(x*d,y*d);}
	Point operator/(double d){return Point(x/d,y/d);}
	double operator==(Point p){return cmp(x,p.x)==0&&cmp(y,p.y)==0;}
	double dot(Point p){return x*p.x+y*p.y;}
	double det(Point p){return x*p.y-y*p.x;}
	double abs2(){return x*x+y*y;}
	double abs(){return sqrt(abs2());}
	Point unit(){return *this/abs();}
	Point rot90(){return Point(-y,x);}
}p[1000005],goal;
int o[1005],p1[1005],p2[1005],numc,numl,tot,nums,a[15];
double d[1005];
bool flag;
bool cmp(Point a,Point b)
{
	if(fabs(a.x-b.x)/max(1.0,fabs(b.x))<=1e-5&&fabs(a.y-b.y)/max(1.0,fabs(b.y))<=1e-5)return 1;
	else return 0;
}
double dis(Point p1,Point p2){return (p2-p1).abs();}
double disLP(Point p1,Point p2,Point p)
{
	return fabs((p-p1).det(p2-p1)/(p2-p1).abs());
}
bool onLine(Point p1,Point p2,Point p)
{
	return disLP(p1,p2,p)<EPS;
}
bool isMiddle(double a,double m,double b)
{
	if(a>b)swap(a,b);
	return cmp(a,m)!=1&&cmp(m,b)!=1;
}
bool isMiddle(Point a,Point m,Point b)
{
	return isMiddle(a.x,m.x,b.x)&&isMiddle(a.y,m.y,b.y);
}
Point isLL(Point p1,Point p2,Point q1,Point q2)
{
	double d1=(q2-q1).det(p2-q1);
	double d2=(p1-q1).det(q2-q1);
	return p1+(p2-p1)/(d1+d2)*d2;
}
pair<Point,Point>isCL(Point o,double r,Point p1,Point p2)
{
	double d=(p2-p1).det(p2-o)/(p2-p1).abs();
	Point m=o+(p2-p1).rot90().unit()*d;
	d=(m-o).abs2();
	d=r*r-d;
	d=max(d,0.0);
	d=sqrt(d);
	Point dr=(p2-p1).unit()*d;
	return make_pair(m-dr,m+dr);
}
pair<Point,Point>isCC(Point o1,double r1,Point o2,double r2)
{
	double d=(o2-o1).abs2();
	double cosc=(r1*r1+d-r2*r2)/(2*sqrt(d)*r1);
	d=cosc*r1;
	Point m=o1+(o2-o1).unit()*d;
	d=r1*r1-(m-o1).abs2();
	d=max(d,0.0);
	d=sqrt(d);
	Point dr=(o2-o1).unit().rot90()*d;
	return make_pair(m+dr,m-dr);
}
void ins_C(int x,double r)
{
	o[++numc]=x;
	d[numc]=r;
	for(int i=1;i<=numc;i++)
	{
		if(dis(p[o[numc]],p[o[i]])>d[numc]+d[i]+EPS)continue;
		if(dis(p[o[numc]],p[o[i]])<fabs(d[numc]-d[i])+EPS)continue;
		pair<Point,Point>ans=isCC(p[o[i]],d[i],p[o[numc]],d[numc]);
		for(int i=1;i<=tot;i++)
		{
			if(p[i]==ans.first)break;
			if(i==tot)p[++tot]=ans.first;
		}
		for(int i=1;i<=tot;i++)
		{
			if(p[i]==ans.second)break;
			if(i==tot)p[++tot]=ans.second;
		}
		if(cmp(ans.first,goal))flag=1;
		if(cmp(ans.second,goal))flag=1;
	}
	for(int i=1;i<=numl;i++)
	{
		if(disLP(p[p1[i]],p[p2[i]],p[o[numc]])>r+EPS)continue;
		pair<Point,Point>ans=isCL(p[o[numc]],r,p[p1[i]],p[p2[i]]);
		if(i<=nums&&!isMiddle(p[p1[i]],ans.first,p[p2[i]]))ans.first=Point(0,0);
		if(i<=nums&&!isMiddle(p[p1[i]],ans.second,p[p2[i]]))ans.second=Point(0,0);
		for(int i=1;i<=tot;i++)
		{
			if(p[i]==ans.first)break;
			if(i==tot)p[++tot]=ans.first;
		}
		for(int i=1;i<=tot;i++)
		{
			if(p[i]==ans.second)break;
			if(i==tot)p[++tot]=ans.second;
		}
		if(cmp(ans.first,goal))flag=1;
		if(cmp(ans.second,goal))flag=1;
	}
}
void ins_L(int pp1,int pp2)
{
	p1[++numl]=pp1;
	p2[numl]=pp2;
	for(int i=1;i<=numc;i++)
	{
		if(disLP(p[p1[numl]],p[p2[numl]],p[o[i]])>d[i]+EPS)continue;
		pair<Point,Point>ans=isCL(p[o[i]],d[i],p[p1[numl]],p[p2[numl]]);
		for(int j=1;j<=tot;j++)
		{
			if(p[j]==ans.first)break;
			if(j==tot)p[++tot]=ans.first;
		}
		for(int j=1;j<=tot;j++)
		{
			if(p[j]==ans.second)break;
			if(j==tot)p[++tot]=ans.second;
		}
		if(cmp(ans.first,goal))flag=1;
		if(cmp(ans.second,goal))flag=1;
	}
	for(int i=1;i<numl;i++)
	{
		if(sign((p[p2[numl]]-p[p1[numl]]).det(p[p2[i]]-p[p1[i]]))==0)continue;
		Point ans=isLL(p[p1[numl]],p[p2[numl]],p[p1[i]],p[p2[i]]);
		if(i<=nums&&!isMiddle(p[p1[i]],ans,p[p2[i]]))ans=Point(0,0);
		for(int j=1;j<=tot;j++)
		{
			if(p[j]==ans)break;
			if(j==tot)p[++tot]=ans;
		}
		if(cmp(ans,goal))flag=1;
	}
}
int main(int argc,char*argv[])
{
	// registerTestlibCmd(argc, argv);
	// tot=inf.readInt();
	// tot=inf.readInt();
    	fin=fopen(argv[1],"r");//标准输入
	fout=fopen(argv[2],"r");//用户输出
	fstd=fopen(argv[3],"r");//标准输出
	perScore = atoi(argv[4]);
	fscore=fopen(argv[5],"w");//得分文件
	freport=fopen(argv[6],"w");//报告文件

    fscanf(fin, "%d", &tot);
	for(int i=1;i<=tot;i++)
	{
		// p[i].x=inf.readDouble();
		// p[i].y=inf.readDouble();
fscanf(fin, "%lf%lf", &p[i].x, &p[i].y);
	}
	// nums=inf.readInt();
    fscanf(fin, "%d", &nums);
	for(int i=1;i<=nums;i++)
	{
        int x, y;
        fscanf(fin, "%d%d", &x, &y);
		// int x=inf.readInt(),y=inf.readInt();
		ins_L(x,y);
	}
	// int n=inf.readInt();
    int n;
    fscanf(fin, "%d", &n);
	for(int i=1;i<=n;i++)
	{
		// int x=inf.readInt(),y=inf.readInt();
        int x, y;
        fscanf(fin, "%d%d", &x, &y);
		ins_L(x,y);
	}
	// n=inf.readInt();
    fscanf(fin, "%d", &n);
	for(int i=1;i<=n;i++)
	{
		// int x=inf.readInt(),y=inf.readInt();
        int x, y;
        fscanf(fin, "%d%d", &x, &y);
		ins_C(x,dis(x,y));
	}
        fscanf(fin, "%d%d", &goal.x, &goal.y);
	// goal.x=inf.readDouble();
	// goal.y=inf.readDouble();
	// for(int i=1;i<=10;i++)a[i]=inf.readInt();
    for(int i=1;i<=10;i++)fscanf(fin, "%d", &a[i]);

	// int m=ouf.readInt(0,2147483647);
    int m;
    fscanf(fout, "%d", &m);
	if(m>a[1])
	{
        fprintf(freport, "too many steps.a[1] is %d,your answer is %d",a[1],m);
		quit(0.0);
		return 0;
	}
	flag=0;
	for(int o=1;o<=m;o++)
	{
        int type;
        fscanf(fout, "%d", &type);
		// int type=ouf.readInt(1,2);
        double x1, y1, x2, y2;
        fscanf(fout, "%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
		// double x1=ouf.readDouble(),y1=ouf.readDouble(),x2=ouf.readDouble(),y2=ouf.readDouble();
		int p1=0,p2=0;
		double minn=1e100;
		for(int i=1;i<=tot;i++)
		{
			if(dis(p[i],Point(x1,y1))<minn)
			{
				minn=dis(p[i],Point(x1,y1));
				p1=i;
			}
		}
		if(minn>1e-5){
            fprintf(freport, "point(%.8lf,%.8lf) not found",x1,y1);
            quit(0.0);
        }
        
        
		minn=1e100;
		for(int i=1;i<=tot;i++)
		{
			if(dis(p[i],Point(x2,y2))<minn)
			{
				minn=dis(p[i],Point(x2,y2));
				p2=i;
			}
		}
		if(minn>1e-5){
            fprintf(freport, "point(%.8lf,%.8lf) not found",x2,y2);
            quit(0.0);
        }
        
        
        // quit(_wa,"point(%.8lf,%.8lf) not found",x2,y2);
		if(p1==p2){
            fprintf(freport, "point(%.8lf,%.8lf) and point(%.8lf %.8lf) coincide",x1,y1,x2,y2);
            quit(0.0);
        }
        //
		if(type==1)ins_C(p1,dis(p[p1],p[p2]));
		else ins_L(p1,p2);
		if(flag==1)
		{
			int x=1;
			while(m<=a[x])x++;
			x--;
			if(x==10)
			{
                fprintf(freport, "Perfect Answer.your answer is %d",m);
            quit(1.0);
				// quit(_ok,"Perfect Answer.your answer is %d",m);
				return 0;

			}
            fprintf(freport, "Partially Correct get %d percent",x);
            quit(x/10.0);
			// quitp(x/10.0,"Partially Correct get %d percent",x);
			return 0;
		}
	}
    fprintf(freport, "point(%.8lf,%.8lf) not found",goal.x,goal.y);
            quit(0.0);
	// quit(_wa,);
	return 0;
}