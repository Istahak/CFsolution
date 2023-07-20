#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
void solve()
{
    int n;
    cin >> n;
    if (n >= 20)
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    ll ans = 1;
    while (n--)
    {
        cout << ans << ' ';
        ans *= 3ll;
    }
    cout << endl;
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
