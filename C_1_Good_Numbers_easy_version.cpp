#include <bits/stdc++.h>
#define ll long long int
using namespace std;
vector<int> pw(13);
void solve()
{
    ll n;
    cin >> n;
    bool ok = true;
    ll ans = n;
    vector<int> v;
    while (n)
    {
        int k = n % 3;
        n /= 3;
        if (k == 2)
            ok = false;
        v.push_back(k);
    }
    if (ok)
    {
        cout << ans << endl;
        return;
    }
    v.push_back(0);
    int tt;
    int sz = v.size();
    for (int i = 0; i < sz; i++)
    {
        if (v[i] == 2)
            tt = i;
    }
    for (int i = tt + 1; i < sz; i++)
    {
        if (v[i] == 0)
        {
            for (int j = 0; j < i; j++)
                v[j] = 0;
            v[i] = 1;
            break;
        }
    }
    ll p = 1;
    ans = 0;
    for (int i = 0; i < sz; i++)
    {
        ans += p * v[i];
        p *= 3;
    }
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pw[0] = 1;
    for (int i = 1; i < 13; i++)
        pw[i] = pw[i - 1] * 3;
    int t = 1;
    cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case #" << cs << ": ";
        solve();
    }
    return 0;
}