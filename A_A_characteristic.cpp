#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int n, k;
int ok(int x)
{
    ll f = x * (x - 1);
    f >>= 1;
    return f;
}
void solve()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int a = i;
        int b = n - i;
        if (ok(a) + ok(b) == k)
        {
            cout << "YES" << endl;
            while (a--)
            {
                cout << -1 << ' ';
            }
            while (b--)
            {
                cout << 1 << ' ';
            }
            cout << endl;
            return;
        }
    }
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