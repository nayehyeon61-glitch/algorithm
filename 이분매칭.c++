#include<bits/stdc++.h>
using namespace std;
vector<int> v[2020];
bool visited[2020];
int parent[2020];
bool dfs(int cur)
{
    for(int i=0;i<v[cur].size();i++)
    {
        int nxt=v[cur][i];
        if(visited[nxt])continue;
        visited[nxt]=true;
        if(parent[nxt]==0||dfs(parent[nxt]))
        {
            parent[nxt]=cur;
            return true;
        }
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N,M;
    cin>>N>>M;
    for(int i=1;i<=N;i++)
    {
        int cnt;
        cin>>cnt;
        for(int j=0;j<cnt;j++)
        {
            int y;
            cin>>y;
            v[i].push_back(y);
        }
    }
    int ans=0;
    for(int i=1;i<=N;i++)
    {
        fill(visited,visited+2020,false);
        if(dfs(i))
            ans++;
    }
    cout<<ans;
}
