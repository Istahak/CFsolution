#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
void solve()
{
    int n;
    cin >> n;
    ll sum = 0;
    vector<int> v(n);
    unordered_map<int, int> mp;
    for (auto &i : v)
    {
        cin >> i;
        mp[i]++;
        sum += i;
    }
    if ((2 * sum) % n != 0)
    {
        cout << 0 << endl;
        return;
    }
    ll ans = 0;
    ll d = (2 * sum) / n;
    for (int i = 0; i < n; i++)
    {
        int x = d - v[i];
        if (mp[x])
            ans += mp[x];
        if (x == v[i])
            ans--;
    }
    cout << ans / 2 << endl;
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
