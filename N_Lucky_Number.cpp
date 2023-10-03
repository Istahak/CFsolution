#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    map<int, int> cnt;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        cnt[x % 5]++;
    }
    int ans = 0;
    ans += cnt[0];
    cnt[0] = 0;
    int x1 = min(cnt[1], cnt[4]);
    cnt[1] -= x1, cnt[4] -= x1;
    ans += x1;
    x1 = min(cnt[2], cnt[3]);
    cnt[2] -= x1, cnt[3] -= x1;
    ans += x1;
    x1 = min(cnt[2] / 2, cnt[1]);
    cnt[2] -= (x1 * 2), cnt[1] -= x1;
    ans += x1;
    x1 = min(cnt[1] / 2, cnt[3]);
    cnt[1] -= (x1 * 2), cnt[3] -= x1;
    ans += x1;
    x1 = min(cnt[1] / 3, cnt[2]);
    cnt[1] -= (x1 * 3), cnt[2] -= x1;
    ans += x1;
    for (int i = 1; i <= 4; i++)
    {
        ans += cnt[i] / 5;
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
        // cout << "Case #" << cs << ": ";
        solve();
    }
    return 0;
}