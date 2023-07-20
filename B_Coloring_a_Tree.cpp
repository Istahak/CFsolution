#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e4 + 4;
vector<int> adj[N + 1], col(N);
int n, ans = 0;
void dfs(int vertex, int cur_colour)
{
    if (col[vertex] == cur_colour)
    {
        for (auto child : adj[vertex])
        {
            dfs(child, cur_colour);
        }
    }
    else
    {
        ans++;
        for (auto child : adj[vertex])
        {
            dfs(child, col[vertex]);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        int x;
        cin >> x;
        adj[x].push_back(i);
    }
    for (int i = 1; i <= n; i++)
        cin >> col[i];
    dfs(1, 0);
    cout << ans << endl;

    return 0;
}