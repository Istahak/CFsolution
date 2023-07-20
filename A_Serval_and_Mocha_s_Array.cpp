#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    bool ok = false;
    for (int i = 0; i < n; i++)
    {
        int gc = a[i];
        for (int j = i; j < n; j++)
        {
            gc = __gcd(a[i], a[j]);
            if (gc <= 2)
                ok = true;
        }
    }

    cout << (ok ? "Yes" : "No") << endl;
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