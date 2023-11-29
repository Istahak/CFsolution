#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &x : v)
        cin >> x;
    int pos = n - 1;
    map<int, bool> mp;
    for (int i = 0; i < k; i++)
    {
        if (mp[pos])
        {
            cout << "Yes" << '\n';
            return;
        }
        if (v[pos] > n)
        {
            cout << "No" << '\n';
            return;
        }
        mp[pos] = true;
        pos = (pos - v[pos]) % n;
        if (pos < 0)
            pos += n;
    }
    cout << "Yes" << '\n';
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