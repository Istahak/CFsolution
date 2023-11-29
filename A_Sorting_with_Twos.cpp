#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    v[0] = v[1] = -2000;
    for (int k = 2; k <= n; k *= 2)
    {
        for (int i = 1; i <= k; i++)
        {
            if (v[i - 1] > v[i])
            {
                cout << "NO"
                     << "\n";
                return;
            }
        }
        for (int i = 1; i <= k; i++)
        {
            v[i] = -2000;
        }
    }
    if (is_sorted(v.begin(), v.end()))
        cout << "YES"
             << "\n";
    else
        cout << "NO\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case #" << cs << ": ";
        solve();
    }
    return 0;
}