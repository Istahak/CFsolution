#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
void solve()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    vector<ll> v;
    ll mid = 0;
    for (int i = 0; i < n; i++)

    {
        if (i > n - 1 - i && s[i] == 'R')
            v.push_back(2 * i + 1 - n);
        else if (s[i] == 'L' && i < n - 1 - i)
            v.push_back(n - 1 - 2 * i);
        if (s[i] == 'L')
            mid += i;
        else
            mid += (n - i - 1);
    }
    sort(v.rbegin(), v.rend());
    ll ans = 0;
    for (int i = 0; i < v.size(); i++)
    {
        ans += v[i];
        cout << ans + mid << ' ';
    }
    for (int i = v.size(); i < n; i++)
        cout << ans + mid << ' ';
    cout << endl;
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