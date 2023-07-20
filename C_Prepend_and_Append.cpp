#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    string s;
    cin >> n >> s;
    int l = 0, r = n - 1;
    int ans = 0;
    while (l < r)
    {
        if (s[l] != s[r])
        {
            l++, r--;
        }
        else
            break;
    }
    ans = r - l + 1;
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