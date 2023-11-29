#include <bits/stdc++.h>
#define ll long long int
using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#endif

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> cnt(26, 0);
    for (int i = 0; i < n;)
    {
        int c = 1;
        int cur = s[i] - 'a';
        while (i < n - 1 and s[i] == s[i + 1])
            i++, c++;
        i++;
        cnt[cur] = max(c, cnt[cur]);
    }
    ll ans = 0;
    for (int i = 0; i < 26; i++)
    {
        ans += cnt[i];
    }
    cout << ans << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case " << cs << ": ";
        solve();
    }
    return 0;
}