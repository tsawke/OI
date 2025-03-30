#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E

/******************************
abbr

******************************/

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;



template<typename T = int>
inline T read(void);


int n;
char s[1005];
map<string,char>mp;
int main(){
    cin >> n;
    mp["UUU"]=mp["UUC"]='F';
    mp["UUA"]=mp["UUG"]=mp["CUU"]=mp["CUC"]=mp["CUA"]=mp["CUG"]='L';
    mp["AUU"]=mp["AUC"]=mp["AUA"]='I';
    mp["AUG"]='M';
    mp["GUU"]=mp["GUC"]=mp["GUA"]=mp["GUG"]='V';
    mp["UCU"]=mp["UCC"]=mp["UCA"]=mp["UCG"]=mp["AGU"]=mp["AGC"]='S';
    mp["CCU"]=mp["CCC"]=mp["CCA"]=mp["CCG"]='P';
    mp["ACU"]=mp["ACC"]=mp["ACA"]=mp["ACG"]='T';
    mp["GCU"]=mp["GCC"]=mp["GCA"]=mp["GCG"]='A';
    mp["UAU"]=mp["UAC"]='Y';
    mp["CAU"]=mp["CAC"]='H';
    mp["CAA"]=mp["CAG"]='Q';
    mp["AAU"]=mp["AAC"]='N';
    mp["AAA"]=mp["AAG"]='K';
    mp["GAU"]=mp["GAC"]='D';
    mp["GAA"]=mp["GAG"]='E';
    mp["UGU"]=mp["UGC"]='C';
    mp["UGG"]='W';
    mp["CGU"]=mp["CGC"]=mp["CGA"]=mp["CGG"]=mp["AGA"]=mp["AGG"]='R';
    mp["GGU"]=mp["GGC"]=mp["GGA"]=mp["GGG"]='G';
    mp["UAA"]=mp["UAG"]=mp["UGA"]=1;
    while(n--) {
        string ans="";
        scanf("%s",s+1);
        int L=strlen(s+1);
        for(int i=1;i<=L;i+=3) {
            string c="";
            c+=s[i];
            c+=s[i+1];
            c+=s[i+2];
            if(mp.find(c)!=mp.end()) {
                if(mp[c]==1) {
                    break;
                }
                ans+=mp[c];
            }
        }
        cout << ans << '\n';
    }
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