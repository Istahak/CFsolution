#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
void solve()
{
    ll n;
    cin >> n;
    vector<pair<ll, ll>> arr(n);
    ll minn = INT_MAX;
    for (int i = 0; i < n; ++i)
    {
        ll x;
        cin >> x;
        arr[i] = {x, i};
        minn = min(minn, arr[i].first);
    }
    sort(arr.begin(), arr.end());
    vector<pair<ll, ll>> ans;
    for (int i = 0; i < n; ++i)
    {
        if (arr[i].first % minn == 0)
        {
            minn = max(minn, arr[i].first);

            continue;
        }
        else
        {
            ll x = (arr[i].first / minn) * minn + minn - arr[i].first;
            ans.push_back({arr[i].second, x});
            minn = max(minn, x + arr[i].first);
        }
    }
    cout << ans.size() << endl;
    for (auto p : ans)
    {
        cout << p.first + 1 << ' ' << p.second << endl;
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