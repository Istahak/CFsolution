#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<ll> h(n), p(n);
    for (auto &i : h)
        cin >> i;
    for (auto &i : p)
        cin >> i;

    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        if (h[i] > k)
            v.push_back({p[i], h[i]});
    }
    ll mx = *max_element(h.begin(), h.end());
    sort(v.begin(), v.end());
    ll sum = k;
    for (int i = 0; i < v.size(); i++)
    {
        while (v[i].second > sum)
        {
            k -= v[i].first;
            if (k < 0)
                break;
            sum += k;
        }
        if (k < 0)
            break;
    }
    cout << (((sum >= mx) || k > 0) ? "YES" : "NO") << endl;
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