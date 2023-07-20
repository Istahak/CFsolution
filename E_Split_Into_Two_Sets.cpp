#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
const int N = 2e5 + 7;
int color[N], flag, vis[N];
vector<int> g[N];
void DFS(int vertex)
{
    if (vis[vertex])
        return;
    vis[vertex] = 1;
    for(auto child:g[vertex])
    {
        if(vis[child]==0)
        {
            color[child]=color[vertex]^1;
            DFS(child);
        }
        else if(color[child]==color[vertex])
            flag=false;
    }
}
void reset(int n)
{
    for (int i = 0; i <= n; i++)
    {
        g[i].clear();
        vis[i] = 0;
        color[i] = 0;
        flag = true;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    cin >> t;
    while (t--)
    {
        
        int n;
        cin >> n;
        reset(n);
        for (int i = 1; i <= n; i++)
        {
            int x, y;
            cin >> x >> y;
            if (x == y)
                flag = false;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        for (int i = 1; i <= n; i++)
            if (g[i].size() != 2)
                flag = false;
        for (int i = 1; i <= n; i++)
        {
            if (vis[i] == 0)
            {
                color[i] = 1;
                DFS(i);
            }
        }

        cout<<(flag ? "YES" : "NO")<<endl;
    }

    return 0;
}
