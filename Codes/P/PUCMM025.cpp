#include <bits/stdc++.h>
using namespace std;

bool divBySeven(char *s, int len)
{
    int rem=0,num;
    for(int i=0; i<len; i++)
    {
        num = 10*rem + (s[i]-'0');
        rem = num%7;
    }
    if(rem==0) return true;
    else return false;
}

int main()
{
    int len,sum,ans;
    char s[250];
    while(scanf("%s",s) != EOF)
    {
        sum=0;ans=0;
        int a[10]={0},b[10]={0};
        b[1]=1;
        len = strlen(s);
        for(int i=0; i<len; i++)
        {
            a[s[i]-'0']++;
            sum+=s[i]-'0';
        }
        int i=0;
        while(s[i]-'0'==0) i++;
        for(int z=0; i<=len; z++) s[z]=s[i++];
        len = strlen(s);
        if((s[len-1]-'0')%2==0) b[2]=1;
        if(sum%3==0) b[3]=1;
        if(len==1)
        {
            if(s[len-1]%4==0) b[4]=1;
            if(s[len-1]%8==0) b[8]=1;
        }
        else
        {
            if((10*(s[len-2]-'0')+(s[len-1]-'0'))%4==0) b[4]=1;
            if(len<=2 && (10*(s[len-2]-'0')+(s[len-1]-'0'))%8==0) b[8]=1;
            if(len>2 && ((100*(s[len-3]-'0')+10*(s[len-2]-'0')+(s[len-1]-'0'))%8==0)) b[8]=1;
        }
        if((s[len-1]-'0')%5==0) b[5]=1;
        if(b[2]&b[3]==1) b[6]=1;
        if(divBySeven(s,len)) b[7]=1;
        if(sum%9==0) b[9]=1;
        for(int i=1; i<10; i++)
        {
            if(b[i]==1 && a[i]!=0) ans+=a[i];
        }
        printf("%d\n",ans);
    }
    return 0;
}

