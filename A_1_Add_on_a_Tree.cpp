#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
const int N = 1e5 + 2;
vector<int> g(N, 0);
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u]++, g[v]++;
    }
    string ans = "YES";
    for (int i = 1; i <= n; i++)
    {
        if (g[i] == 2)
            ans = "NO";
    }
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    // cin >> t;
    while (t--)
    {

        solve();
    }

    return 0;
}