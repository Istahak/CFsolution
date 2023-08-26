#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    map<int, int> mp;
    for (auto &x : v)
        cin >> x, mp[x]++;
    if (n == 1)
    {
        cout << "NO" << endl;
        return;
    }
    ll sum = accumulate(v.begin(), v.end(), 0LL);
    ll need = mp[1] * 2 + (n - mp[1]);
    if (sum >= need)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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