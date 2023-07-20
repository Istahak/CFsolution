#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    int a = 0, b = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x & 1)
        {
            b += x;
        }
        else
        {
            a += x;
        }
    }

    if (a > b)
        cout << "YES\n";
    else
        cout << "NO\n";
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
