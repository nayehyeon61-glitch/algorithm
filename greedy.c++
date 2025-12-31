#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> arr;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    ll M;
    cin>>N>>M;
    for(int i=0;i<N;i++)
    {
        ll a;
        cin>>a;
        arr.push_back(a);
    }
    sort(arr.begin(),arr.end());
    int cnt=0;
    for(int i=N-1;i>=0;i--)
    {
        cnt+=M/arr[i];
        M%=arr[i];
    }
    cout<<cnt;
}
