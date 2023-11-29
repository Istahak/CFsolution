#include <bits/stdc++.h>
#define ll long long int
using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#endif
map<pair<int, int>, ll> cnt;
ll ber_kor(int a, int b)
{
    if (a <= b)
        return 0;
    if (cnt.find({a, b}) != cnt.end())
        return cnt[{a, b}];
    else
        return cnt[{a, b}] = ber_kor(a / 2, b) + ber_kor((a + 1) / 2, b) + 1;
}
void solve()
{
    cout << ber_kor(37, 4) << '\n';
    int cc = 0, cc1 = 0;
    int cur = 4;
    int tmp = 37;
    int tmp2 = 37;
    // cnt.clear();
    int ans = 0;
    // ans += ber_kor(v[i], cur);
    while (cur < tmp)
    {
        tmp = (tmp + 1) / 2;
        cc++;
    }
    while (cur < tmp2)
    {
        tmp2 = (tmp2) / 2;
        cc1++;
    }
    int y = 37 - tmp2 * (1 << cc1);
    ans += (1 << cc1) - 1;
    ans += y;
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