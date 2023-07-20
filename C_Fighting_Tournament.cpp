#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
//long long int a, b;
void solve()
{
    int n,q;
    cin>>n>>q;
    vector<vector<ll>>v(n+1);
    int mx=INT_MIN;
    int cnt=0;
    int x,ro=0;
    cin>>x;
    mx=x;
    int po=1;
    for(int i=2;i<=n;i++)
    {
        cin>>x;
        if(x>mx)
        {   
            ro++;
            v[po][0]=mx;
            v[po][1]=cnt;
            v[po][2]=ro;
            mx=x;
            cnt=0;
            cnt++;
            po=i;

        }
        else
        {
            ro++;
            cnt++;
            v[i][0]=x;
            v[i][1]=0;
            v[i][2]=ro;
        }

    }
    while(q--)
    {
        int x,y;
        cin>>x>>y;

        if(v[x][1]==0){cout<<0<<endl;return;}
        
 
}
int main()
{    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t=1;
    cin>>t;
    while(t--)
    {
     
     solve();
 
    }
 
   return 0;
}   