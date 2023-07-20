#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
//long long int a, b;
void solve()
{
    int n;
    cin>>n;
    std::vector<ll>v;
    for(int i=1;;i++)
    {
        ll x=(i*(i+1))/2;
        if(x<=n)v.push_back(x);
        else break;
    }
   int l=0,r=v.size()-1;
   bool flag=false;
   while(l<=r)
   {
    if(v[l]+v[r]==n){flag=true;break;}
    else if(v[l]+v[r]<n)l++;
    else r--;
   }
   cout<<(flag ? "YES":"NO")<<endl;
   
}
int main()
{    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t=1;
    //cin>>t;
    while(t--)
    {
     
     solve();
 
    }
 
   return 0;
}   