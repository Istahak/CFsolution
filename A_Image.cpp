#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
//long long int a, b;
void solve()
{
   map<char,int>mp;
   set<char>s;
   for(int i=0;i<4;i++)
   {
    char c;
    cin>>c;
    s.insert(c);
   } 
   if(s.size()==1){cout<<0<<endl;return;}
   if(s.size()==2){cout<<1<<endl;return;}
   if(s.size()==3){cout<<2<<endl;return;}
   if(s.size()==4){cout<<3<<endl;return;}


 
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