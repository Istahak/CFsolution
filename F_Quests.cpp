#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
const int N = 2 * 1e5 + 3;
ll n, c, d;
vector<ll> v(N);
bool ispossible(ll mid)
{
    ll sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i > mid + 1)
            break;

        ll k = ((d - i) / (mid + 1)) + 1;
        k *= v[i];
        sum += k;
    }
    return sum >= c;
}
ll Binaryserach(ll l, ll r)
{
    ll ans = -1;
    while (l <= r)
    {
        ll mid = l + (r - l) / 2;

        if (ispossible(mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    return ans;
}
void solve()
{
    cin >> n >> c >> d;
    vector<ll> vf(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vf[i];
    }
    sort(vf.rbegin(), vf.rend());
    for (int i = 0; i < n; i++)
    {
        v[i + 1] = vf[i];
    }

    ll sum1 = 0, k = d;

    for (int i = 0; i < n; i++)
    {
        if (k == 0)
            break;
        sum1 += vf[i];
        k--;
    }
    if (sum1 >= c)
    {
        cout << "Infinity" << endl;
        return;
    }
    ll flag = Binaryserach(0, d);
    // cout << flag << endl;
    if (flag != -1)
        cout << flag << endl;
    else
        cout << "Impossible" << endl;
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