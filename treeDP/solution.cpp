#include<iostream>             
#include<vector>   
#include<bits/stdc++.h>
#define mod 1000000007
#define pi 3.14159265358979
#define  PRE(x,p) cout<<setprecision(x)<<p; 
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl "\n"
#define high INT_MAX
#define low INT_MIN
#define ll long long int
#define mem(x) memset(x,0,sizeof(x));
#define rep(i,l,r) for(i=l;i<=r;i++)
#define rep0(i,l,r) for(i=l;i<r;i++)

using namespace std;


void showa(ll a[],ll n) { for(ll i=1;i<=n;i++) cout<<a[i]<<' ';  cout<<endl;  }
void showv(vector<ll>v) { for(ll i=0;i<v.size();i++) cout<<v[i]<<' '; cout<<endl;}
void add(ll &x, ll y)   {  x=(x+y)%mod; }
vector<ll>vec[200005];
ll depth[200005];
ll dis[200005],ans[200005];
map<pair<ll,ll>,ll>ma;  
void dfs0(ll u, ll p)
{
   ll j,v;
   depth[u]=0;
   for(j=0;j<vec[u].size();j++)
   {
      v=vec[u][j];
      if(v==p) continue;
      dfs0(v,u);
      depth[u]=max(depth[u],depth[v]+1);
   }

}
void dfs(ll u,ll p)
{
    multiset<ll>st;
    for(ll v:vec[u])
    {
      if(v==p) continue;
      st.insert(depth[v]);
      
    }
    for(ll v:vec[u])
    {
      if(v==p) continue;
      auto it=st.find(depth[v]);
      st.erase(it);
      if(st.size()==0)  ma[{u,v}]=max(1+ma[{p,u}],0ll);
      else{
      auto pt=st.end();
      pt--;
      ma[{u,v}]=max(1+ma[{p,u}],1+*pt);}
  
      st.insert(depth[v]);
      dfs(v,u);
     
    }
    
    ans[u]=max(1+ma[{p,u}],depth[u]);
    




}
void solve() 
{ 
   ll n,i;
   cin>>n;
   
   for(i=1;i<n;i++)
   {
      ll u,v;
      cin>>u>>v;
      vec[u].pb(v);
      vec[v].pb(u);
   }
   mem(dis);
   dfs0(1,0);
   ma[{0,1}]=-1;
   dfs(1,0);
   showa(ans,n);
}
int main()
{
 #ifndef ONLINE_JUDGE
 freopen("input.txt", "r", stdin);
 freopen("output.txt", "w", stdout);
 #endif
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

ll t=1;
// cin>>t;
for(ll test=1;test<=t;test++)
{
    // cout<<"CASE #"<<test<<": ";
    solve();
}

return 0;
}

