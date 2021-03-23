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
#define ll  int

using namespace std;

ll m,n,k;
vector<pair<ll,ll>>edges;
bool vis[100005];
vector<ll>s;
deque<int> cycle;
vector<ll>vec[100005];
ll pos[100005];
ll color[100005];
vector<ll>a,b;      //a for 0 color b for 1
bool ok=true;
void coloring(ll u)
{  
     vis[u]=true;
     if(color[u]==0)
     a.pb(u);
     else
     b.pb(u);
     for(ll j=0;j<vec[u].size();j++)
     {
            if(!vis[vec[u][j]])
            {
                    color[vec[u][j]]=1-color[u];
                    coloring(vec[u][j]);
            }
     }
}

void dfs(int u,int parent)
{
   if(!ok)
   return;
    vis[u]=true;
    s.push_back(u);
    int val;
    for (ll j=0;j<vec[u].size();j++)
    {
        if(!vis[vec[u][j]])
        dfs(vec[u][j],u);
        else if(cycle.empty() && vec[u][j]!=parent)
        {    
            for(ll i=s.size()-1;i>=0;i--)
            {
                    cycle.pb(s[i]);
                    if(s[i]==vec[u][j])
                    break;
            }
            ok=false;
           
        }
    }
    s.pop_back();
}
void solve() 
{ 
   
  cin>>n>>m>>k;
  ll i,u,v;
  for(i=1;i<=m;i++)
  {
          cin>>u>>v;
          vec[u].pb(v);
          vec[v].pb(u);
          edges.pb({u,v});
  }
 if(m!=(n-1))
 {
         dfs(1,-1);
 }
 for(i=1;i<=n;i++) pos[i]=-1;
 for(i=0;i<cycle.size();i++)
 {
         pos[cycle[i]]=i;
 }
 
for(i=0;i<edges.size();i++)
{
        
        u=edges[i].f;
        v=edges[i].s;
        
  if(pos[u]!=-1 && pos[v]!=-1 && abs(pos[v]-pos[u])!=1)
      {
 while (cycle.front()!=u && cycle.front()!=v)
                {
                        pos[cycle.front()]=-1;
                    cycle.pop_front();
                }
                while (cycle.back()!=u && cycle.back()!=v)
                {
                     pos[cycle.back()]=-1;
                    cycle.pop_back();
                }
         
      }
     
      
        
}
 
 if(cycle.size()<=k && !cycle.empty())
 {
         cout<<2<<endl<<cycle.size()<<endl;
         for(i=0;i<cycle.size();i++)
         cout<<cycle[i]<<' ';
         
 }
 else
 {
      for(i=1;i<=n;i++)
      {color[i]=-1;
      vis[i]=false;}
      color[1]=0;
      coloring(1);
      cout<<1<<endl;
      if(a.size()>=b.size())
      {for(i=0;i<(k+1)/2;i++)
      cout<<a[i]<<' ';}
      else
      {for(i=0;i<(k+1)/2;i++)
      cout<<b[i]<<' ';}
       
 }
  

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

