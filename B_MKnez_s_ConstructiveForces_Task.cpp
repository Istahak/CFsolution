#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    if (n == 3)
    {
        cout << "NO" << endl;
        return;
    }
    if (n % 2 == 0)
    {
        cout << "YES" << endl;

        for (int i = 0; i < n / 2; i++)
        {
            cout << 2 << ' ' << -2 << ' ';
        }
        cout << endl;
    }
    else
    {
        cout << "YES" << endl;
        for (int i = 0; i < n / 2; i++)
        {
            cout << n / 2 - 1 << ' ' << -n / 2 << ' ';
        }
        cout << n / 2 - 1 << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    tt = 1;
    cin >> tt;
    while (tt--)
        solve();

    return 0;
}