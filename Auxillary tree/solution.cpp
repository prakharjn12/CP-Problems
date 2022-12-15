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
#define sz(a)        (ll)a.size()
#define po(x)        (ll)(1ll<<x)
#define all(x)       begin(x), end(x)
#define speed        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define yes          {cout<<"YES"<<endl;return;}
#define no           {cout<<"NO"<<endl; return;}
#define ok           cout<<"ok"<<endl;
#define ordered_set  tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>


using namespace std;
using namespace __gnu_pbds;

void showa(ll a[],ll n)  { for(ll i=1;i<=n;i++) cout<<a[i]<<' ';  cout<<endl;  }
ll ison(ll w ,ll i)    {return  w&(1ll<<i);}
void amax(ll &a, ll b){ a=max(a,b); }
void amin(ll &a, ll b){ a=min(a,b);}
void modadd(ll &a , ll b) {a=((a%mod)+(b%mod))%mod;}
void modsub(ll &a , ll b) {a=((a%mod)-(b%mod)+mod)%mod;}
void modmul(ll &a , ll b) {a=((a%mod)*(b%mod))%mod;}

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

//const ll l=30;   //log2(n)
//const ll N=200005;

const ll l=30;  // log(n)
const ll N=500005;
vll vec[N];
ll up[N][l];
ll depth[N],tin[N],tout[N];
ll timer;
ll pre[N];
void dfs(ll u, ll p)
{
   tin[u] = timer++;
   up[u][0] = p;
   rep(i,1,l-1) up[u][i] = up[up[u][i-1]][i-1];
   depth[u]=depth[p]+1;
   for(ll v:vec[u])
   {
    if(v==p) continue;
    dfs(v,u);
   }  
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
ll dist(ll u, ll v)
{
  return depth[u]+depth[v]-2*depth[lca(u,v)];
}
map<pll,ll>idx;
ll ans[N];
ll a[N];
bool comp(ll &a, ll&b)
{
    return tin[a]<tin[b];
}

void build_auxillary(vll here , ll color)
{
   stack<ll>st;
   ll prev=-1;
   for(ll u:here)
   {
    if(u==prev) continue;
     while(st.size() && !is_ancestor(st.top(),u))
            st.pop();
     
     if(st.size())
     {
        pre[u]+=color;
        pre[st.top()]-=color;
     }
     st.push(u);
     prev=u;
   }
}
void dfs2(ll u , ll p)
{
    for(ll v:vec[u])
    {
        if(v==p) continue;
        dfs2(v,u);
        pre[u]+=pre[v];
    }
    if(p) ans[idx[{min(u,p),max(u,p)}]]=pre[u];
}
void solve()
{
  ll n;
  cin>>n;
  rep(i,1,n)
  {
    vec[i].clear();
    rep(j,0,l-1) up[i][j]=0;
    pre[i]=0;
  }

  map<ll,vll>ma;
  idx.clear();
  rep(i,1,n) {cin>>a[i]; ma[a[i]].pb(i);}
  rep(i,1,n-1)
  {
    ll u,v;
    cin>>u>>v;
    vec[u].pb(v);
    vec[v].pb(u);
    if(u>v) swap(u,v);
    idx[{u,v}]=i;
  }
  dfs(1,1);
  rep(i,1,n-1) ans[i]=0;

  for(auto it:ma)
  {
    vll here=it.s;
    if(here.size()==1) continue;
    
    sort(all(here),comp);
    ll k=sz(here);
    for(ll i=0;i<=k-2;i++)
    {
        here.pb(lca(here[i],here[i+1]));
    }
    sort(all(here),comp);
    build_auxillary(here,it.f);
  }
  dfs2(1,0);
  showa(ans,n-1);
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
  cin>>t;
  
  for(ll test=1;test<=t;test++)
  {
    solve();
  }
  return 0;
}      
