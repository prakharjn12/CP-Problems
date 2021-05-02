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

class Solution {
public:



    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        
        
        ll n=rooms.size(),i,j,m=queries.size(),m1,m2;
        vector<int>ans(m);
     
        vector<pair<pair<ll,ll>,ll>>q;
        for(i=0;i<m;i++)
        q.pb({{queries[i][0],queries[i][1]},i});
        
        
        sort(rooms.begin(), rooms.end(),  [](const vector<int>& a, const std::vector<int>& b) {
          if(a[1]==b[1]) return a[0]<b[0];
     
           return a[1]<b[1];
       });
        sort(q.begin(),q.end(),  [](const pair<pair<ll,ll>,ll>&a,  const pair<pair<ll,ll>,ll>&b) {
          if(a.f.s==b.f.s) return a.f.f<b.f.f;
     return a.f.s<b.f.s;
       });
        
//          for(i=0;i<n;i++) {
//             cout<<rooms[i][0]<<' '<<rooms[i][1]<<endl;
//         }        // output rooms
//          for(i=0;i<m;i++) {
//             cout<<q[i].f.f<<' '<<q[i].f.s<<' '<<q[i].s<<endl;
//         }          // output queries
        
        set<ll>st;
        for(i=0;i<n;i++)
        {
            st.insert(rooms[i][0]);
        }
        
        // finding answer for each query;
        i=0;
        for(j=0;j<m;j++)
        {
            while(i<n && rooms[i][1]<q[j].f.s)
            {
                st.erase(rooms[i][0]);
                i++;
            }
            ll pref=q[j].f.f;
            ll index=q[j].s;
            
            if(st.size()==0)
            {
                ans[index]=-1;
                // cout<<j<<' '<<"-1 is"<<endl;
                continue;
            }
            
             auto it=st.lower_bound(pref);
            
                        if(it==st.begin())
                   {
                           m1=low;
                           m2=*it;
                   }
                   else if(*st.rbegin()<pref)
                   {
                           m1=*st.rbegin();
                           m2=low;
                   }
                   else
                   {
                           m2=*it;
                           it--;
                           m1=*it;
                   }
            
            // cout<<m1<<' '<<m2<<endl;
            if(abs(m1-pref)<=abs(m2-pref))  ans[index]=m1;
            else                            ans[index]=m2;
            
            
        }
        
        return ans;
    }
};
