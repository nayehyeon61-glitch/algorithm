#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> tree,arr;
void init(int s,int e,int node)
{
    if(s==e)tree[node]=arr[s];
    else
    {
        int mid=(s+e)/2;
        init(s,mid,2*node);
        init(mid+1,e,2*node+1);
        tree[node]=tree[2*node]+tree[2*node+1];
    }
}
void update(int s,int e,int node,int idx,ll val)
{
    if(idx<s||idx>e)return;
    if(s==e)
    {
        tree[node]=val;
        return;
    }
    else
    {
        int mid=(s+e)/2;
        update(s,mid,2*node,idx,val);
        update(mid+1,e,2*node+1,idx,val);
        tree[node]=tree[2*node]+tree[2*node+1];
    }
       
    
}
ll query(int s,int e,int node,int l,int r)
{
    if(l>e||r<s)return 0;
    if(l<=s&&e<=r)return tree[node];
    else
    {
        int mid=(s+e)/2;
        return query(s,mid,2*node,l,r)+query(mid+1,e,2*node+1,l,r);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N,T,R;
    cin>>N>>T>>R;
    int h=(int)ceil(log2(N));
    tree.resize(1<<(h+1));
    arr.resize(N);
    T+=R;
    for(int i=0;i<N;i++)
        cin>>arr[i];
    init(0,N-1,1);
    while(T--)
    {
        int a;
        cin>>a;
        if(a%2)
        {
            int b;
            ll c;
            cin>>b>>c;
            update(0,N-1,1,b-1,c);
        }
        else
        {
            int b,c;
            cin>>b>>c;
            cout<<query(0,N-1,1,b-1,c-1)<<"\n";
        }
    }
}
