#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    ll cnt1 = 0, cnt0 = 0;
    for (auto c : s)
    {
        c == '1' ? cnt1++ : cnt0++;
    }
    ll ans = cnt1 * cnt0, x = 1;
    for (int i = 1; i < n; i++)
    {
        if (s[i - 1] == s[i])
            x++;
        else
        {
            ans = max(ans, x * x);
            x = 1;
        }
    }
    ans = max(ans, x * x);

    cout << ans << endl;
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