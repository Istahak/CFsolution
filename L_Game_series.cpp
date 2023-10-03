#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    ll a1, p1, a2, p2;
    cin >> a1 >> p1 >> a2 >> p2;
    a1 += a2;
    p1 += p2;
    if (a1 > p1)
    {
        cout << "A\n";
    }
    else if (p1 > a1)
    {
        cout << "P\n";
    }
    else
    {
        cout << "D\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case #" << cs << ": ";
        solve();
    }
    return 0;
}