// problem link : https://www.spoj.com/problems/COT2/





#include             <bits/stdc++.h>
#include             <ext/pb_ds/assoc_container.hpp>
#include             <ext/pb_ds/tree_policy.hpp>
#define PRE(x,p)     cout<<setprecision(x)<<p; 
#define pb           push_back
#define mp           make_pair
#define f            first
#define s            second
#define pi           3.14159265358979
#define mod          (ll)(1e9 + 7)
#define endl         "\n"
#define high         1e18
#define low          -1e18
#define ll           long long int
#define ld           long double
#define mem(x,val)   memset(x,0,sizeof(x));
#define rep(i,l,r)   for(ll i=l;i<=r;i++)
#define p(a)         for(auto i:a) cout<<i<<' '; cout<<endl;
#define vll          vector<ll> 
#define vb           vector<bool>
#define vpll         vector<pair<ll,ll>>
#define vi           vector<int>
#define vpi          vector<pair<int, int>>
#define vvll         vector<vector<ll>>
#define vvi          vector<vector<int>>
#define vvvll        vector<vector<vector<ll>>>
#define pll          pair<ll,ll>
#define vs           vector<string>
#define vvpll        vector<vector<pair<ll, ll>>>
#define vvpi         vector<vector<pair<int, int>>>
#define vpii         vector<pair<int, int>>
#define all(x)       begin(x), end(x)
#define speed        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define yes          {cout<<"YES"<<endl;return;}
#define no           {cout<<"NO"<<endl; return;}
#define ok           cout<<"ok"<<endl;

const ll l=30;
using namespace std;

using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

void showa(ll a[],ll n)  { for(ll i=1;i<=n;i++) cout<<a[i]<<' ';  cout<<endl;  }

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
void _print(ll t)     {cerr << t<<' ';}
void _print(int t)    {cerr << t<<' ';}
void _print(string t) {cerr << t<<' ';}
void _print(char t)   {cerr << t<<' ';}
void _print(ld t)     {cerr << t<<' ';}
void _print(double t) {cerr << t<<' ';}
template<class T,class V> void _print(pair <T, V> p);
template<class T>void _print(vector <T> v);
template<class T>void _print(vector <T> v);
template<class T>void _print(set <T> v);
template<class T,class V> void _print(map <T, V> v);
template<class T>void _print(multiset <T> v);
template<class T,class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.f); cerr << ","; _print(p.s); cerr << "}";}
template<class T>void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template<class T>void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template<class T>void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template<class T,class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

const ll N=400005;


struct query{
  ll l,  r,  extra,idx;
};
vll vec[N];
ll up[N][l];
ll a[N];
ll depth[N],tin[N],tout[N];
ll euler[N];
ll timer;
void dfs(ll u, ll p)
{
   euler[timer]=u;
   tin[u] = timer++;
   up[u][0] = p;
   rep(i,1,l-1) up[u][i] = up[up[u][i-1]][i-1];
   // depth[u]=depth[p]+1;
   for(ll v:vec[u])
   {
    if(v==p) continue;
    dfs(v,u);
   }  
   euler[timer]=u;
   tout[u]=timer++;
}
bool is_ancestor(ll u, ll v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}
ll lca(ll u, ll v)
{
    if (is_ancestor(u, v)) return u;
    if (is_ancestor(v, u))  return v;
    for (ll i = l-1; i >= 0; --i) 
       if(!is_ancestor(up[u][i], v)) u = up[u][i];
    
    return up[u][0];
}
  ll sq;
  ll ma[N];
  ll added[N]; //how many times this vertex is added up
  ll cnt;
void add(ll l)
  {
     ll vertex=euler[l];
     if(added[vertex]==0)
     {
       added[vertex]=1;
       ma[a[vertex]]++;
       if(ma[a[vertex]]==1) cnt++;
     }
     else
     {
       added[vertex]=2;
       ma[a[vertex]]--;
       if(ma[a[vertex]]==0) cnt--;  
     }

  }
  void remove(ll l)
  {
     ll vertex=euler[l];
     if(added[vertex]==2)
     {
       added[vertex]=1;
       ma[a[vertex]]++;
       if(ma[a[vertex]]==1) cnt++;
     }
     else
     {
       added[vertex]=0;
       ma[a[vertex]]--;
       if(ma[a[vertex]]==0) cnt--;  
     }
  }
  bool comp(query &a ,query &b)
  {
     if(a.l/sq == b.l/sq) return a.r<b.r ; 
     else return a.l/sq < b.l/sq;
  }
void solve() 
{ 
   ll n,q;
   cin>>n>>q;
   rep(i,1,n)
   {
     vec[i].clear();
     ma[i]=0;
     added[i]=0;
     rep(j,0,l) up[i][j]=0;
   }
   sq=sqrt(n);
   map<ll,vll>ma1;
   rep(i,1,n) {cin>>a[i]; ma1[a[i]].pb(i);}
   ll p=1;
   for(auto it:ma1)
   {
     for(ll v:it.s) a[v]=p;
      p++;
   }
   rep(i,1,n-1)
   {
    ll u,v;
    cin>>u>>v;
    vec[u].pb(v);
    vec[v].pb(u);
   }
   timer=1;
   dfs(1,1);
   // showa(euler,2*n);
   cnt=0;
   query qq[q+1];
   rep(i,1,q)
   {
    ll u,v;
    cin>>u>>v;
    ll l=lca(u,v);
    if(l==u) {
      qq[i]={tin[u],tin[v],0,i};
    }
    else if(l==v)
    {
      qq[i]={tin[v],tin[u],0,i};
    }
    else
    {
         if(tin[u]>tin[v]) swap(u,v);
         qq[i]={tout[u],tin[v],tin[l],i};
    }

  }
  // rep(i,1,q) cout<<qq[i].l<<' '<<qq[i].r<<endl;
  // return;
    ll ans[q+1];
    sort(qq+1,qq+q+1,comp);
    ll L=1,R=0; 
    for(ll i=1;i<=q;i++)
    {
       ll l=qq[i].l;
       ll r=qq[i].r;
       // debug(l) debug(r)
       ll idx=qq[i].idx;
       ll extra=qq[i].extra;
         while(r<R)
       {
           // remove L
           remove(R--);
       }
         while(r>R)
       {
           // remove L
           add(++R);
       }
       // debug(i) continue;
        while(l<L)
       {
           // remove L
           add(--L);
       }
         while(L<l)
       {
           // remove L
           remove(L++);
       }
       if(extra) add(extra);
       ans[idx]=cnt;
      if(extra) remove(extra);
    }
    rep(i,1,q) cout<<ans[i]<<endl;
   // showa(ans,q);
  }

signed main()
{
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("err.txt", "w", stderr);
  freopen("output.txt", "w", stdout);
  #endif 
  speed

  ll t=1;
  // cin>>t;
  
  for(ll test=1;test<=t;test++)
  {
    // cout<<"Case #"<<test<<": ";
    solve();
  }
  return 0;
}      
