#include<bits/stdc++.h>
#define mod 1000000007
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

vector<ll>vec[200005];
bool vis[200005];
ll p[200005],dis[200005];

void dfs(ll u)
{
        vis[u]=true;
        for(ll j=0;j<vec[u].size();j++)
        {
                if(vis[vec[u][j]]) continue;
                
                p[vec[u][j]]=u;
                dis[vec[u][j]]=dis[u]+1;
                dfs(vec[u][j]);
        }
}
void solve() 
{ 
   ll n,i,u,v;
   cin>>n;
   
   for(i=1;i<=n;i++)
   {
           vis[i]=false;
           vec[i].clear();
           p[i]=0;
           dis[i]=0;
   }
   
    for(i=1;i<n;i++)
   {
           cin>>u>>v;
           vec[u].pb(v);
           vec[v].pb(u);
   }
   
   ll da,db,dc;
   dfs(1);
   
   ll max_d=*max_element(dis+1,dis+n+1);
   
   for(i=1;i<=n;i++)
   {
           if(dis[i]==max_d)
           da=i;
           
   }
    for(i=1;i<=n;i++)
   {
           vis[i]=false;
           
           p[i]=0;
           dis[i]=0;
   }
   dfs(da);
    max_d=*max_element(dis+1,dis+n+1);
   
   for(i=1;i<=n;i++)
   {
           if(dis[i]==max_d)
           db=i;
           
   }
   
    i=db;
   
   vector<ll>diam;
   while(1)
   {
          diam.pb(i);
          
           if(i==da) break;  
          else i=p[i];
           
          
   }
  
   
   
   
   
   if(diam.size()==n)
    {
            cout<<n-1<<endl;
            cout<<da<<' '<<db<<' ';
            for(i=1;i<=n;i++)
            {
                    if(i!=da && i!=db)
                   { cout<<i;break;}
            }
            return;
   
    }
      for(i=1;i<=n;i++)
   {
           vis[i]=false;
           
           p[i]=0;
           dis[i]=0;
   }
    for(i=0;i<diam.size();i++)
    vis[diam[i]]=true;
   
    for(i=0;i<diam.size();i++)
    dfs(diam[i]);
    
    max_d=*max_element(dis+1,dis+n+1);
      for(i=1;i<=n;i++)
   {
           if(dis[i]==max_d)
           dc=i;
           
   }
    
    cout<<diam.size()-1 + max_d<<endl<<da<<' '<<db<<' '<<dc;
    
   
   
   
  

}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

ll t=1;
// cin>>t;
while(t--)
solve();
return 0;
}

