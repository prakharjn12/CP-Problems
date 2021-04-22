#include<bits/stdc++.h>
#define mod 1000000007
#define pi 3.14159265358979
#define PRE(x,p) cout<<setprecision(x)<<p; 
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl "\n"
#define high INT_MAX
#define low INT_MIN
#define ll long long int
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
ll tc;
void showv(vector<ll>v)
{
	for(ll i=0;i<v.size();i++) cout<<v[i]<<' ';
	cout<<endl;
}
void showa(ll a[],ll n)
{
	for(ll i=1;i<=n;i++) cout<<a[i]<<endl;
	cout<<endl;
}
ll n,sq;
bool comp(pair<pair<ll,ll>,ll> &a ,pair<pair<ll,ll>,ll>&b)
{
    if(a.f.f/sq == b.f.f /sq) return a.f.s < b.f.s;
    return a.f.f/sq < b.f.f/sq;
}


vector<pair<pair<ll,ll>,ll>>vec;
ll a[300005],ans[200005];
void solve()
{
    ll q,i,l,r,idx;
   cin>>n;
   sq=sqrt(n);
  
   for(i=1;i<=n;i++) cin>>a[i];
   cin>>q;
   for(i=1;i<=q;i++)
   {
      cin>>l>>r;
      vec.pb({{l,r},i});
   }
   sort(vec.begin(),vec.end(),comp);
   ll L=vec[0].f.f;
   ll R=vec[0].f.f;
   ll freq[1000000]={0};
   freq[a[L]]=1;
   ll cnt=1;  //that u are on
//   cout<<L<<' '<<R<<endl;
   for(i=0;i<q;i++)
   {
       //currently at index i
       
       l=vec[i].f.f;
       r=vec[i].f.s;
       idx=vec[i].s;
       
       while(L<l)   //deleting from ur set
       {
           freq[a[L]]--;
           if(freq[a[L]]==0) cnt--;
           L++;
       }
       while(L>l)   //adding ur set
       {
           L--;
           freq[a[L]]++;
           if(freq[a[L]]==1) cnt++;
           
       }
       while(R<r)  //adding ur set
       {
           R++;
           freq[a[R]]++;
           if(freq[a[R]]==1) cnt++;
           
       }
       while(R>r)   //deleting from ur set
       {
           freq[a[R]]--;
           if(freq[a[R]]==0) cnt--;
           R--;
       }
       ans[idx]=cnt;
        // cout<<L<<' '<<R<<endl;
        // showa(freq,3);
       
       
   }
   showa(ans,q);
    
}

int main()
{

  fast_io;
//     #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
//     #endif 
ll t=1;
// cin>>t;
for(tc=1;tc<=t;tc++)
{
 // cout<<"Case #"<<tc<<": ";
 solve();
}
return 0;
}

