#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n, k, n, h, m, ls, ans;
    char d;
    cin >> n >> k >> n;
    cin >> h >> h >> d >> m;
    ls = m + h * 60;
    ans = 1;
    for (int i = 2; i <= n; i++)
    {
        cin >> h >> h >> d >> m;
        m += h * 60;
        if (m - ls > k)
            ++ans;
        ls = m;
    }
    cout << ans << '\n';
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