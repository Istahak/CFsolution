#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        int xx;
        cin >> xx;
        v[i] = xx * (n - i);
    }
    sort(v.begin(), v.end());
    int ans = 0;
    for (auto xx : v)
    {
        if (xx <= x)
        {
            x -= xx;
            ans++;
        }
    }
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t = 1;
    // cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case #" << cs << ": ";
        solve();
    }
    return 0;
}