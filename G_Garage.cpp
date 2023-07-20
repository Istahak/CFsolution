#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
int n;
ll numofpossiblecase(ll mid)
{
    ll ans = 0;
    if (mid & 1)
        ans = mid / 2 + 1;
    else
        ans = mid / 2;

    ans--;
    if (mid >= 4)
    {
        ans += mid / 4;
        ans--;
    }
    //cout << ans << ' ' << mid << endl;
    return ans;
}
ll bs(ll l, ll r)
{
    ll ans = -1;
    while (l <= r)
    {
        ll mid = l + (r - l) / 2;
        ll flag = numofpossiblecase(mid);
        if (flag == n)
        {
            ans = mid;
            r = mid - 1;
        }
        else if (flag > n)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return ans;
}
void solve()
{

    cin >> n;
    cout << bs(1, 1e18) << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    // cin >> t;
    while (t--)
    {

        solve();
    }

    return 0;
}
