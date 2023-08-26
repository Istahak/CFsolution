#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for (auto &x : v)
        cin >> x;
    vector<pair<ll, int>> st;
    ll tim = 0;
    int i = 0, j = n - 1;
    int cnt = 0;
    st.push_back({0, n});
    while (i <= j)
    {
        int mi = min(v[i], v[j]);
        if (v[i] == v[j] and i == j)
        {
            i++, j--;
            cnt++;
            tim += mi;
            st.push_back({tim, n - cnt});
            continue;
        }
        v[i] -= mi;
        v[j] -= mi;
        tim += mi;
        if (v[i] == 0)
        {
            i++;
            cnt++;
            st.push_back({tim, n - cnt});
        }
        if (v[j] == 0)
        {
            j--;
            cnt++;
            st.push_back({tim, n - cnt});
        }
    }
    while (q--)
    {
        ll s;
        cin >> s;
        int l = 0, r = st.size() - 1;
        int ans = 0;
        while (l <= r)
        {
            int m = (l + r) / 2;
            auto [x, y] = st[m];
            if (x <= s)
            {
                l = m + 1;
                ans = y;
            }
            else
                r = m - 1;
        }
        cout << ans << endl;
    }
    cout << endl;
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