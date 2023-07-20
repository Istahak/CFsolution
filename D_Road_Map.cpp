#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 5e4 + 10;
vector<int> adj[N];
int par[N];
void dfs(int vertex, int parent)
{
    par[vertex] = parent;
    for (auto child : adj[vertex])
    {
        if (child == parent)
            continue;
        dfs(child, vertex);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, r1, r2;
    cin >> n >> r1 >> r2;
    for (int i = 1; i <= n; i++)
    {
        if (i == r1)
            continue;
        int x;
        cin >> x;
        adj[x].push_back(i);
        adj[i].push_back(x);
    }
    dfs(r2, -1);
    for (int i = 1; i <= n; i++)
    {
        if (r2 == i)
            continue;
        cout << par[i] << ' ';
    }
    cout << endl;
    return 0;
}
