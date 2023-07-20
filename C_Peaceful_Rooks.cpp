#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
const int N = 1e5 + 10;
vector<int> parent(N);
void make(int v)
{
    parent[v] = v;
}
int find(int v)
{
    if (parent[v] == v)
        return v;
    else
        return parent[v] = find(parent[v]);
}
void union_sets(int a, int b)
{
    if (a != b)
        parent[b] = a;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    int ans = m;
    for (int i = 1; i <= n; i++)
        make(i);
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        if (x == y)
        {
            ans--;
            continue;
        }
         x = find(x);
         y = find(y);
        if (x == y)
        {
            ans++;
            continue;
        }
        union_sets(x, y);
    }
    cout << ans << endl;
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
