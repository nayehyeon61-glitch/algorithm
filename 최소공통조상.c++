#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e4+1;
vector<ll> adj[MAX];
ll parent[MAX][21];
int level[MAX];
int depth[MAX];
int maxlv;
int r;
void init()
{
     memset(level,0,sizeof(level));
     memset(depth,0,sizeof(depth));
    for(int i=0;i<MAX;i++)
    {
        adj[i].clear();
        for(int j=0;j<21;j++)
            parent[i][j]=0;
    }
}
void set_tree(int cur,int par,int lv)
{
    parent[cur][0]=par;
    level[cur]=lv;
    for(int i=1;i<=maxlv;i++)
    {
        parent[cur][i]=parent[parent[cur][i-1]][i-1];
    }
    for(int i=0;i<adj[cur].size();i++)
    {
        int nxt=adj[cur][i];
        if(nxt==par)continue;
        set_tree(nxt,cur,lv+1);
            
    }
}
int LCA(int a,int b)
{
    if(a==r||b==r)return r;
    if(level[a]<level[b])swap(a,b);
    int dif=level[a]-level[b];
    for(int i=0;dif;i++)
    {
        if(dif%2)a=parent[a][i];
        dif>>=1;
    }
    if(a==b)return a;
    for(int i=maxlv;i>=0;i--)
    {
        if(parent[a][i]^parent[b][i])
        {
            a=parent[a][i];
            b=parent[b][i];
        }
    }
    return parent[a][0];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
         int N;
        cin>>N;
        maxlv=(int)ceil(log2(N));
        for(int i=1;i<=N-1;i++)
        {
            int a,b;
            cin>>a>>b;
            adj[a].push_back(b);
            depth[b]++;
        }
        for(int i=1;i<=N;i++)
            if(depth[i]==0)
                r=i;
        set_tree(r,0,1);
        int a,b;
        cin>>a>>b;
        int ans=LCA(a,b);
        cout<<ans<<"\n";
        init();
    }
    
}
