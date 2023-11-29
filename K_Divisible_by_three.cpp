#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    string s;
    cin >> n >> s;
    vector<ll> cnt(3, 0);
    ll sum = 0;
    for (auto c : s)
    {
        sum += (c - '0');
        sum %= 3;
        cnt[sum % 3]++;
    }
    ll ans = 0;
    for (int i = 0; i < 3; i++)
    {
        ans += (cnt[i] * (cnt[i] - 1) / 2);
    }
    cout << ans + cnt[0] << '\n';
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