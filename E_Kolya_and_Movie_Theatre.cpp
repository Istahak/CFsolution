#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    ll n, m, d;
    cin >> n >> m >> d;
    vector<ll> v(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    priority_queue<ll> st;
    ll ans = 0;
    ll sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (v[i] <= 0)
        {
            // cnt++;
            continue;
        }
        else
        {
            st.emplace(-v[i]);
            sum += v[i];
            if (st.size() > m)
            {
                sum += st.top();
                st.pop();
            }
        }
        ans = max(ans, sum - i * d);
    }
    cout << ans << endl;
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