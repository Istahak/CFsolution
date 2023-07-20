#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
void solve()
{
    int n;
    cin >> n;
    if (n & 1)
    {
        int ans = n;
        for (int i = 2; i * i * 1ll <= n; i++)
        {
            if (n % i == 0)
            {
                ans = i;
                break;
            }
        }
        ans = n / ans;
        cout << ans << ' ' << n - ans << endl;
    }
    else
    {
        cout << n / 2 << ' ' << n / 2 << endl;
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