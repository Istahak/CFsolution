#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
const int N = 2 * 1e5 + 2;
vector<int> g[N];
vector<bool> vis(N);
vector<int> ans;
int x, y, n;
bool flag=true;
void DFS(int x)
{
    if (vis[x])
        return;
    vis[x] = true;
    ans.push_back(x);
    // cout << x << endl;
    if (x == y && flag)
    {
        for (auto i : ans)
            cout << i << ' ';
        cout << endl;
        flag=false;
        return;
    }
    for (auto child : g[x])
        DFS(child);

    ans.pop_back();
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> x >> y;
    for (int i = 1; i < n; i++)
    {
        int p, q;
        cin >> p >> q;
        g[p].push_back(q);
        g[q].push_back(p);
    }
    DFS(x);

    return 0;
}
