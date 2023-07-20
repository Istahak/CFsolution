#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << n << endl;
        return;
    }
    if (n & 1)
    {
        cout << -1 << endl;
        return;
    }
    vector<int> v(n + 1, 0);
    int x = n, y = 1;
    for (int i = 1; i <= n / 2; i++)
    {
        if (i & 1)
        {
            v[i] = x;
            v[n - i + 1] = x - 1;
            x -= 2;
        }
        else
        {
            v[i] = y;
            v[n - i + 1] = y + 1;
            y += 2;
        }
    }
    for (int i = 1; i <= n; i++)
        cout << v[i] << ' ';
    cout << endl;
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