#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;

void solve()
{
    vector<bool> v(50000, true);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        v[x] = false;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += v[i];
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