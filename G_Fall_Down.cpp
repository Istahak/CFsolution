#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<string> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (v[j][i] != '*')
                continue;
            ll x = j + 1;
            while (x < n && v[x][i] == '.')
            {
                swap(v[x][i], v[x - 1][i]);
                x++;
            }
        }
    }
    for (auto u : v)
    {
        cout << u << "\n";
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

        solve();
    }

    return 0;
}