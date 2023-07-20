#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n, m;
    cin >> n >> m;
    ll tt = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        tt += x;
    }
    ll ttt = 0;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        ttt += x;
    }
    if (tt == ttt)
    {
        cout << "Draw" << endl;
    }
    else if (tt > ttt)
    {
        cout << "Tsondu" << endl;
    }
    else
    {
        cout << "Tenzing" << endl;
    }
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