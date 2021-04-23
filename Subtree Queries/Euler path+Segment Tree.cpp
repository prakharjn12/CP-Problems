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
 
using namespace std;
 
ll test;
ll n;
ll a[200005];
ll tin[200005],tout[200005],euler[400005],timer;
vector<ll>vec[200005];
ll t[800005];
void showa(ll a[],ll n){ for(ll i=0;i<n;i++) cout<<a[i]<<' '; cout<<endl;}
void showv(vector<ll>v){ for(ll i=0;i<(ll)v.size();i++) cout<<v[i]<<' ';cout<<endl;}
 
 
 
 
void build() {  
    for (ll i = 0; i < 2*n; ++i)  t[2*n +i]=a[euler[i]];    
    for (ll i = 2*n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];
}
void update(ll p, ll value) 
{
  for (t[p += 2*n] = value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
}
ll query(ll l, ll r) {  // sum on interval [l, r)
  ll res = 0;
  for (l += 2*n, r += 2*n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res += t[l++];
    if (r&1) res += t[--r];
  }
  return res;
}
void dfs(ll u, ll p)
{
    ll j,v;
    tin[u]=timer;
    euler[timer++]=u;
    for(j=0;j<(ll)vec[u].size();j++)
    {
        v=vec[u][j];
        if(v==p) continue;
        
        dfs(v,u);
    }
     tout[u]=timer;
     euler[timer++]=u;
}
void solve() 
{ 
    timer=0;
    ll q,i,u,v;
   cin>>n>>q;
   for(i=0;i<n;i++) cin>>a[i];
   for(i=1;i<n;i++)
   {
       cin>>u>>v;
       u--;v--;
       vec[u].pb(v);
       vec[v].pb(u);
       
   }
   dfs(0,-1);
   build();
//   showa(euler,2*n);
//   showa(t,4*n);
  while(q--)
  {
      int type;
      cin>>type;
      if(type==1)        // update value of node s to x
      {
          ll s,x;      
         cin>>s>>x;
         s--;
        
         
         update(tin[s],x);
         update(tout[s],x);
        
        //  showa(t,4*n);
      }
      
      else
      {
          ll s;
          cin>>s;   //tell subtree sum of s
          s--;
          cout<<query(tin[s],tout[s]+1)/2<<endl;
      }
  }
   
 
 
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
 
ll t=1;
// cin>>t;
for(test=1;test<=t;test++)
{
    // cout<<"CASE #"<<test<<": ";
    solve();
}
 
return 0;
}
