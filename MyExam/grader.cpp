#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

FILE* fin;//标准输入
FILE* fout;//用户输出
FILE* fstd;//标准输出
FILE* fscore;//得分文件
FILE* freport;//报告文件
int perScore;

void quit(double x, int type = 0)
{
	fprintf(fscore,"%d\n", int(x*perScore+0.5));
	
	if(type >= 0)
	{
		fprintf(freport, "Check Error at pos[%d]\n", type);
	}
	else switch(type)
	{
		case -1:
			fprintf(freport, "Check Error!\n");
			break;
		case -2:
			fprintf(freport, "strlen &gt; 2*Q!\n");
			break;
		case -3:
			fprintf(freport, "P and Q calc Error!\n");
			break;
		default:
			fprintf(freport, "Unkown Error!\n");
			break;
	}
	fclose(fin);
	fclose(fout);
	fclose(fstd);
	fclose(fscore);
	fclose(freport);
	exit(0);
}
const int MAXL = 3e6+1;
char buf[MAXL], str[MAXL];
int main(int argc,char*argv[])
{
	/*
	argv[1]:输入文件
	argv[2]:选手输出文件
	argv[3]:标准输出文件
	argv[4]:单个测试点分值
	argv[5]:输出最终得分的文件
	argv[6]:输出错误报告的文件
	*/
	fin=fopen(argv[1],"r");//标准输入
	fout=fopen(argv[2],"r");//用户输出
	fstd=fopen(argv[3],"r");//标准输出
	perScore = atoi(argv[4]);
	fscore=fopen(argv[5],"w");//得分文件
	freport=fopen(argv[6],"w");//报告文件
	int P, Q;
	fscanf(fin, "%d%d", &P, &Q);
	fgets(buf, MAXL-1, fout);
	sscanf(buf, "%s", str);
	if(int(strlen(str)) > 2*Q) quit(0.0, -2);
	int val = 0, p = 0, q = 0;
	for(int i=0; str[i]; ++i)
	{
		switch(str[i])
		{
			case 's':
				if(val == 0);
				else if(val != -1) quit(0, i);
				break;
			case 'c':
				if(val == 0) val=-1, p = 1, q = 1;
				else if(val != -1) quit(0, i);
				break;
			case 't':
				char c = str[++i];
				switch(c)
				{
					case 's':
						q += p;
						break;
					case 'c':
						std::swap(p, q);
						q += p;
						break;
					default:
						quit(0, i);
						break;
				}
				break;

		}
	}
	if(p == P && q == Q) quit(1.0);
	else quit(0, -3);
}