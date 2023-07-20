#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n, k, x;
    cin >> n >> k >> x;
    if (x != 1)
    {
        cout << "YES" << endl;
        cout << n << endl;
        for (int i = 0; i < n; i++)
        {
            cout << 1 << ' ';
        }
        cout << endl;
        return;
    }
    else if ((k == 1 && x == 1) || n == 1 || (k == 2 && (n & 1)))
    {
        cout << "NO" << endl;
        return;
    }
    if (n % 2 == 0)
    {
        cout << "YES" << endl;
        cout << n / 2 << endl;
        for (int i = 1; i <= n / 2; i++)
            cout << 2 << ' ';
        cout << endl;
        return;
    }
    cout << "YES" << endl;
    n -= 3;
    cout << 1 + n / 2 << endl;
    cout << 3 << ' ';
    for (int i = 1; i <= n / 2; i++)
        cout << 2 << ' ';
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