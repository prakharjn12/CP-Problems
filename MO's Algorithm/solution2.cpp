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
#define mem(x,val) memset(x,0,sizeof(x));
#define rep(i,l,r) for(i=l;i<=r;i++)
#define rep0(i,l,r) for(i=l;i<r;i++)

using namespace std;


void showa(ll a[],ll n) { for(ll i=1;i<=n;i++) cout<<a[i]<<endl;  }
void showv(vector<ll>v) { for(ll i=0;i<v.size();i++) cout<<v[i]<<' '; cout<<endl;}
void add(ll &x, ll y)   {  x=(x+y)%mod; }
ll sq;
bool comp(pair<pair<ll,ll>,ll>&a,pair<pair<ll,ll>,ll>&b)
{
    if(a.f.f/sq == b.f.f/sq) return a.f.s<b.f.s;
    return a.f.f/sq <b.f.f/sq; 
}
void solve() 
{ 
   vector<pair<pair<ll,ll>,ll>>v;
   ll n,q,i,l,r;
   cin>>n>>q;
   ll a[n+1];
   map<ll,ll>ma,to;
   rep(i,1,n) {cin>>a[i];ma[a[i]]++;}
    ll p=1;
   for(auto it:ma)
   {
     to[it.f]=p++;
   }
   for(i=1;i<=n;i++)
    a[i]=to[a[i]];
    // showa(a,n);
   ll freq[n+1];
   mem(freq,0);

   for(i=1;i<=q;i++)
   {
    cin>>l>>r;
    v.pb({{l,r},i});
   }
   sq=sqrt(n);
   sort(v.begin(),v.end(),comp);
   // unordered_map<ll,ll>ma;
   ll cnt=1;  //cnt of distinct values
   ll L=1,R=1;
   freq[a[1]]++;
   ll ans[q+1];
   for(i=0;i<q;i++)
   {
     l=v[i].f.f;
     r=v[i].f.s;
     ll idx=v[i].s;
     // cout<<l<<' '<<r<<endl;
     while(L<l)
     {
        freq[a[L]]--;
        if(freq[a[L]]==0) cnt--;
        L++;
     }
      while(L>l)
     {
        freq[a[L-1]]++;
        if(freq[a[L-1]]==1) cnt++;
        L--;
     }
     while(R>r)
     {
        freq[a[R]]--;
        if(freq[a[R]]==0) cnt--;
        R--;
     }
     while(R<r)
     {
        freq[a[R+1]]++;
        if(freq[a[R+1]]==1) cnt++;
        R++;
     }
     ans[idx]=cnt;


   }
   showa(ans,q);


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
