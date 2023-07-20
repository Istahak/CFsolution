#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int l, r;
    cin >> l >> r;
    int ans = l;
    int mx = INT_MIN;
    for (int k = l; k <= min(l + 101, r); k++)
    {
        string s = to_string(k);
        sort(s.begin(), s.end());
        int d = s.back() - s[0];
        if (mx <= d)
        {
            mx = d;
            ans = k;
        }
    }
    cout << ans << endl;
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
