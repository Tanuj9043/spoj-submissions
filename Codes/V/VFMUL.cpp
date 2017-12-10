#include <bits/stdc++.h>
using namespace std;

#define	PI	3.14159265358979323846

vector<complex<double> > fft(vector<complex<double> > a)
{
    int n = a.size();
    if(n<=1) return a;
    vector<complex<double> > a0(n/2), a1(n/2);

    for(int i=0; i<n/2; i++)
    {
        a0[i] = a[2*i];
        a1[i] = a[2*i+1];
    }

    a0=fft(a0);
    a1=fft(a1);

    double ang=2*PI/n;

    complex<double> w(1), wn(cos(ang),sin(ang));

    for(int i=0; i<n/2; i++)
    {
        a[i] = a0[i] + w*a1[i];
        a[i+n/2] = a0[i] - w*a1[i];

        w*=wn;
    }
    return a;
}

vector<complex<double> > inv_fft(vector<complex<double> > a)
{
    int n=a.size();
    if(n<=1) return a;

    vector<complex<double> > a0(n/2),a1(n/2);

    for(int i=0; i<n/2; i++)
    {
        a0[i]=a[2*i];
        a1[i]=a[2*i+1];
    }

    a0=inv_fft(a0);
    a1=inv_fft(a1);

    double ang=2*PI/n*-1;
    complex<double> w(1), wn(cos(ang),sin(ang));

    for(int i=0; i<n/2; i++)
    {
        a[i]=a0[i]+w*a1[i];
        a[i+n/2]=a0[i]-w*a1[i];
        a[i]/=2;
        a[i+n/2]/=2;
        w*=wn;
    }
    return a;
}

void multiply(vector<int> a, vector<int> b)
{
    vector<complex<double> > fa(a.begin(),a.end()), fb(b.begin(),b.end());

    int n=1;
    while(n<max(a.size(),b.size())) n<<=1;
    n<<=1;

    fa.resize(n);
    fb.resize(n);

    fa = fft(fa);
    fb = fft(fb);

    for(int i=0; i<n; i++)
        fa[i]=fa[i]*fb[i];

    fa = inv_fft(fa);

    vector<int> res(n);
    for(int i=0; i<n; i++)
        res[i]=int(fa[i].real()+0.5);

    int carry=0;
    for(int i=0; i<n; i++)
    {
        res[i]+=carry;
        carry=res[i]/10;
        res[i]%=10;
    }
    bool flag=0;
    for(int i=n-1; i>=0; i--)
    {
        if(res[i]||flag)
        {
            printf("%d",res[i]);
            flag=1;
        }
    }
    if(!flag) printf("0");
    printf("\n");
    return;
}

int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        string x,y;
        vector<int> a,b;
        cin >> x >> y;

        for(int i=0; i<x.length(); i++)
            a.push_back(int(x[i]-'0'));
        for(int i=0; i<y.length(); i++)
            b.push_back(int(y[i]-'0'));

        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        multiply(a,b);
    }
    return 0;
}

