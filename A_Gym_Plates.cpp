#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll dp[101][3][3][3][3][3][3][3][3][3][3];
vector<ll> v;
int n;
vector<int> get(int index)
{
    vector<int> c(10, 0);
    ll val = v[index];
    while (val)
    {
        c[val % 10]++;
        val /= 10;
    }

    return c;
}
ll f(int index, int cnt0, int cnt1, int cnt2, int cnt3, int cnt4, int cnt5, int cnt6, int cnt7, int cnt8, int cnt9)
{
    if (index == n)
        return 0ll;
    ll &ret = dp[index][cnt0][cnt1][cnt2][cnt3][cnt4][cnt5][cnt6][cnt7][cnt8][cnt9];
    if (~ret)
        return ret;
    ret = 0;
    ret = f(index + 1, cnt0, cnt1, cnt2, cnt3, cnt4, cnt5, cnt6, cnt7, cnt8, cnt9);

    auto cur = get(index);
    if (cur[0] + cnt0 <= 2 and cur[1] + cnt1 <= 2 and cur[2] + cnt2 <= 2 and cur[3] + cnt3 <= 2 and cur[4] + cnt4 <= 2 and cur[5] + cnt5 <= 2 and cur[6] + cnt6 <= 2 and cur[7] + cnt7 <= 2 and cur[8] + cnt8 <= 2 and cur[9] + cnt9 <= 2)
    {
        ret = max(ret, f(index + 1, cnt0 + cur[0], cnt1 + cur[1], cnt2 + cur[2], cnt3 + cur[3], cnt4 + cur[4], cnt5 + cur[5], cnt6 + cur[6], cnt7 + cur[7], cnt8 + cur[8], cnt9 + cur[9]) + v[index]);
    }

    return ret;
}
void solve()
{
    cin >> n;
    v.resize(n);
    for (auto &x : v)
        cin >> x;
    memset(dp, -1, sizeof dp);

    cout << f(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0) << endl;
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