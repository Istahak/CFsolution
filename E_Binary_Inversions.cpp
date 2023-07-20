#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
void solve()
{
    int n;
    cin >> n;
    vector<ll> v(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    vector<ll> fcnt(n + 1, 0);
    // vector<int> rcnt(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (v[i] == 0)
            fcnt[i]++;
    }
    for (int i = n; i > 0; i--)
    {
        fcnt[i - 1] = fcnt[i - 1] + fcnt[i];
    }
    ll ans3 = 0;
    for (int i = 1; i <= n; i++)
    {
        if (v[i] == 1)
        {
            ans3 += fcnt[i];
        }
    }
    //cout << ans3 << endl;
    int flag = -1;
    for (int i = 1; i <= n; i++)
    {
        if (v[i] == 0)
        {
            flag = i;
            v[i] = 1;
           // cout << i << endl;
            break;
        }
    }
    vector<ll> cnt(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (v[i] == 0)
            cnt[i]++;
    }
    for (int i = n; i > 0; i--)
    {
        cnt[i - 1] = cnt[i - 1] + cnt[i];
    }

    // for (auto i : cnt)
    //     cout << i << ' ';
    // cout << endl;

    ll ans1 = 0;
    for (int i = 1; i <= n; i++)
    {
        if (v[i] == 1)
        {
            ans1 += cnt[i];
        }
    }
    // cout << ans1 << endl;

    if (flag != -1)
        v[flag] = 0;

    for (int i = n; i > 0; i--)
    {
        if (v[i] == 1)
        {
            v[i] = 0;
            break;
        }
    }
    vector<ll> rcnt(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (v[i] == 0)
            rcnt[i]++;
    }
    for (int i = n; i > 0; i--)
    {
        rcnt[i - 1] = rcnt[i - 1] + rcnt[i];
    }
    ll ans2 = 0;
    for (int i = 1; i <= n; i++)
    {
        if (v[i] == 1)
        {
            ans2 += rcnt[i];
        }
    }
    cout << max({ans2, ans1,ans3}) << endl;
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