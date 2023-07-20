#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
const int N = 1e5 + 10;
vector<int> adj[N], inti(N), goal(N), ans;

void dfs(int vertex, int parent, bool c1, bool c2)
{
    if ((inti[vertex] ^ c1) != goal[vertex])
    {
        ans.push_back(vertex);
        c1 ^= true;
    }
    for (auto child : adj[vertex])
    {
        if (child == parent)
            continue;
        dfs(child, vertex, c2, c1);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for (int i = 1; i <= n; i++)
        cin >> inti[i];
    for (int i = 1; i <= n; i++)
        cin >> goal[i];
    dfs(1, -1, false, false);
    cout << ans.size() << endl;
    for (auto ans : ans)
        cout << ans << endl;

    return 0;
}