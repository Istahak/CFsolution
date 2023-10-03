#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(m);
    for (int &i : v)
        cin >> i;
    int i = 0;
    for (int d = 1; d <= n; d++)
    {
        if (v[i] >= d)
        {
            cout << v[i] - d << '\n';
        }
        if (v[i] == d)
            i++;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case #" << cs << ": ";
        solve();
    }
    return 0;
}