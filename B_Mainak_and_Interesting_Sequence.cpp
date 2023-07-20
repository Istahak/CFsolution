#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
void solve()
{
    int n, m;
    cin >> n >> m;
    if (n > m || (n%2==0 && m%2==1))
    {
        cout << "NO\n";
        return;
    }
    if (n == 1)
    {
        cout << "YES\n";

        cout << m << endl;
        return;
    }
    if (n & 1)
    {
        cout << "YES\n";
        for (int i = 1; i <= n - 1; i++)
        {
            cout << 1 << ' ';
            m--;
        }
        cout << m << endl;
    }
    else
    {
        cout << "YES\n";
        for (int i = 1; i <= n - 2; i++)
        {
            cout << 1 << ' ';
            m--;
        }
        cout << m / 2 << ' ' << m / 2 << endl;
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