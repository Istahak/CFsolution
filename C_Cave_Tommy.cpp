#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    ll x, l, r;
    cin >> x >> l >> r;
    for (ll i = 1; i * i * 1LL <= x; i++)
    {
        if (x % i == 0)
        {
            ll a = x / i;
            for (ll j = 1; j * j <= i; j++)
            {
                if (i % j == 0)
                {
                    ll b = i / j;
                    ll c = j;
                    ll mi = min({a, b, c});
                    ll mx = max({a, b, c});
                    set<int> st;
                    st.insert(a);
                    st.insert(b);
                    st.insert(c);
                    if (st.size() == 3)
                    {
                        if (mi >= l && mx <= r)
                        {
                            for (auto x : st)
                                cout << x << ' ';
                            cout << endl;
                            return;
                        }
                    }
                }
            }
            ll k = a;
            a = i;
            for (ll j = 1; j * j <= k; j++)
            {
                if (k % j == 0)
                {
                    ll b = k / j;
                    ll c = j;
                    ll mi = min({a, b, c});
                    ll mx = max({a, b, c});
                    set<int> st;
                    st.insert(a);
                    st.insert(b);
                    st.insert(c);
                    if (st.size() == 3)
                    {
                        if (mi >= l && mx <= r)
                        {
                            for (auto x : st)
                                cout << x << ' ';
                            cout << endl;
                            return;
                        }
                    }
                }
            }
        }
    }
    cout << -1 << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    tt = 1;
    cin >> tt;
    while (tt--)
        solve();

    return 0;
}
