#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 5005;
int ispal[N][N];
int dp[N][N];
string s;
bool f(int l, int r)
{
    if (l >= r)
        return true;
    if (ispal[l][r] != -1)
        return ispal[l][r];
    if (s[l] != s[r])
        return ispal[l][r] = false;
    else
        return ispal[l][r] = f(l + 1, r - 1);
}
int ff(int l, int r)
{
    if (l == r)
        return 1;
    if (l > r)
        return 0;
    if (dp[l][r] != -1)
        return dp[l][r];
    return dp[l][r] = ff(l + 1, r) + ff(l, r - 1) - ff(l + 1, r - 1) + f(l, r);
}
void solve()
{
    cin >> s;
    memset(ispal, -1, sizeof(ispal));
    memset(dp, -1, sizeof(dp));
    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        l--, r--;
        cout << ff(l, r) << "\n";
    }
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