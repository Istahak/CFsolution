#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
const int N=2*1e5+10;
std::vector<vector<int>>ans;
vector<int>g[N];
vector<int>sans;
//long long int a, b;
void DFS(int root)
{
 sans.push_back(root);
 for(auto child:g[root])DFS(child);
 if(g[root].empty())
 {
 	ans.push_back(sans);
 	sans.clear();
 }   
 
}
void solve()
{
	int n;
	cin>>n;
	int root;
	for(int i=1,x;i<=n;i++) g[i].clear();
	for(int i=1,x;i<=n;i++)
	{
		cin>>x;
		if(x==i)root=x;
		else g[x].push_back(i);
	}
	DFS(root);
	cout<<ans.size()<<endl;
	for(auto i:ans)
	{
		cout<<i.size()<<endl;
			for(auto x:i)cout<<x<<' ';cout<<endl;
	}
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
     ans.clear();
     solve();
 
    }
 
   return 0;
}   