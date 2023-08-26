#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    set<ll> st;
    v[0] = 0;
    for (int i = 1; i < n; i++)
        cin >> v[i];
    for (int i = 1; i <= n; i++)
        st.insert(i);
    ll totalsum = (n * (n + 1));
    totalsum /= 2;
    if (totalsum < v.back())
    {
        cout << "NO" << endl;
        return;
    }
    bool ok = true;
    ll k = -1;
    for (int i = 1; i < n; i++)
    {
        int cur = v[i] - v[i - 1];
        if (cur <= n)
        {
            if (st.count(cur))
            {
                st.erase(cur);
            }
            else if (k == -1)
                k = cur;
            else
                ok = false;
        }
        else
        {
            if (k == -1)
                k = cur;
            else
                ok = false;
        }
    }
    if (k == -1)
    {
        if (st.size() == 1 and ok)
        {
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
        return;
    }
    ll ss = 0;
    // cout << k << endl;
    for (auto x : st)
    {
        ss += x;
        // cout << x << endl;
    }
    cout << ((ss == k and ok) ? "YES" : "NO") << endl;
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