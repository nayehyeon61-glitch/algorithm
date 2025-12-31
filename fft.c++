#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const double PI=acos(-1);

void fft(vector<complex<double>>& a,bool invert)
{
    int n=a.size();
    if(n==1)return;
    vector<complex<double>> a0(n/2);
    vector<complex<double>> a1(n/2);
    for(int i=0;2*i<n;i++)
    {
        a0[i]=a[2*i];
        a1[i]=a[2*i+1];
    }
    fft(a0,invert);
    fft(a1,invert);
   
     double arg=2*PI/n*(invert?-1:1);
    complex<double> w(1),wn(cos(arg),sin(arg));
    for(int i=0;i*2<n;i++)
    {
        
        a[i]=a0[i]+w*a1[i];
        a[i+n/2]=a0[i]-w*a1[i];
        if(invert)
        {
            a[i]/=2;
            a[i+n/2]/=2;
        }
        w*=wn;
        
    }
    
}
vector<ll> mul(vector<ll> v,vector<ll> w)
{
    vector<complex<double>> fv(v.begin(),v.end());
    vector<complex<double>> fw(w.begin(),w.end());
    int n=1;
   while(n<v.size()+w.size())n<<=1;
    fv.resize(n);
    fw.resize(n);
    fft(fv,0);
    fft(fw,0);
    for(int i=0;i<n;i++)fv[i]*=fw[i];
    fft(fv,1);
    vector<ll> res;
    res.resize(fv.size());
    for(int i=0;i<n;i++)
        res[i]=(ll)round(fv[i].real());
    return res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin>>N;
    vector<ll> a(200001);
    vector<ll> b(200001);
    a[0]=1;
    b[0]=1;
    for(int i=0;i<N;i++)
    {
        int x;
        cin>>x;
        a[x]=1;
        b[x]=1;
    }
   
    vector<ll> res=mul(a,b);
    ll ans=0;
    int M;
    cin>>M;
    for(int i=0;i<M;i++)
    {
        ll X;
        cin>>X;
        if(res[X]>0)
            ans++;
    }
    cout<<ans;
        
}
