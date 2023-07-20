#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    ll n, h;
    cin >> n >> h;
    vector<ll> v(n);
    for (auto &x : v)
        cin >> x;
    sort(v.begin(), v.end());
    auto f = [&](int a, int b, int c, ll p)
    {
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            while (v[i] >= p and (a or b or c))
            {
                if (a)
                    p *= a, a = 0;
                else if (b)
                    p *= b, b = 0;
                else if (c)
                    p *= c, c = 0;
            }
            if (v[i] < p)
            {
                ans++;
                p += (v[i] / 2);
            }
        }
        return ans;
    };
    cout << max({f(2, 2, 3, h), f(2, 3, 2, h), f(3, 2, 2, h)})
         << endl;
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