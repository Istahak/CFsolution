#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    ll n, ex;
    cin >> n >> ex;
    n -= ex;
    cout << n / 2 + ex << ' ' << n / 2 << '\n';
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