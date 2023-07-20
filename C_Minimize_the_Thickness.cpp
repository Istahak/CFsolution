#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<ll> v(n), pre(n + 1);
    for (auto &i : v)
    {
        cin >> i;
    }
    pre[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        pre[i] = pre[i - 1] + v[i - 1];
        // cout << pre[i] << ' ';
    }
    int ans = n;
    for (int i = 1; i <= n; i++)
    {
        ll sum = pre[i];
        // cout << pre[i] << endl;
        ll sesum = 0;
        int mx = i;
        int cnt = 0;
        bool ok = true;
        bool ok1 = false;
        for (int j = i; j < n; j++)
        {
            cnt++;
            sesum += v[j];
            if (sesum == sum)
            {
                mx = max(mx, cnt);
                cnt = 0;
                sesum = 0;
                ok1 = true;
                // cout<<mx<<endl;
            }
            else if (sesum > sum)
            {
                ok = false;
                break;
            }
        }
        if (sesum != 0)
            ok = false;
        if (ok && ok1)
            ans = min(ans, mx);
    }
    cout << ans << endl;
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
