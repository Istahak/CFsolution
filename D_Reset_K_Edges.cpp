#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
const int N = 2 * 1e5 + 3;
int k, limit, n, flag = 0;
vector<int> g[N], height(N);
void dfs(int vertex, int par)
{
    height[vertex] = 1;
    for (auto child : g[vertex])
    {
        dfs(child, vertex);
        height[vertex] = max(height[vertex], height[child] + 1);
    }
    if (height[vertex] >= limit && par > 1)
    {
        flag++;
        height[vertex] = 0;
    }
    return;
}
bool is_possible(int mid)
{
    limit = mid;

    for (int i = 0; i <= n; i++)
        height[i] = 0;

    flag = 0;
    dfs(1, 0);
    return flag <= k;
}
int Binary_search(int low, int high)
{
    int ans = -1;
    while (low <= high)
    {
        int mid = low + ((high - low)>>1);
        if (is_possible(mid))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}
void solve()
{

    cin >> n >> k;
    for (int i = 0; i <= n; i++)
    {
        g[i].clear();
    }
    for (int i = 2; i <= n; i++)
    {
        int u;
        cin >> u;
        g[u].push_back(i);
    }
    cout << Binary_search(1, n - 1) << endl;
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

        solve();
    }

    return 0;
}
