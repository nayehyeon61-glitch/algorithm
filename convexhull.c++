#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct p{
    ll x;
    ll y;
};
p operator+(p a,p b)
{
    return {a.x+b.x,a.y+b.y};
}
p operator-(p a,p b)
{
    return {a.x-b.x,a.y-b.y};
}
vector<p> pos,hull;
ll ccw(p a,p b,p c)
{
    p t=b-a;
    p tt=c-a;
    return t.x*tt.y-t.y*tt.x;
}
double dist(p a,p b)
{
    p t=b-a;
    return hypot(t.x,t.y);
}
bool cmp(p a,p b)
{
    if(a.x==b.x)
        return a.y<b.y;
    return a.x<b.x;
}
bool comp(p a,p b)
{
    ll c=ccw(pos[0],a,b);
    if(c==0)
        return cmp(a,b);
    return c>0;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        ll a,b;
        cin>>a>>b;
        pos.push_back({a,b});
    }
    sort(pos.begin(),pos.end(),cmp);
    sort(pos.begin()+1,pos.end(),comp);
    for(int i=0;i<N;i++)
    {
        while(hull.size()>=2)
        {
            p b=hull.back();
            hull.pop_back();
            p a=hull.back();
            if(ccw(a,b,pos[i])>0)
            {
                hull.push_back(b);
                break;
            }
                
        }
        hull.push_back(pos[i]);
    }
        int M=hull.size();
        cout<<M;
    
        
}
