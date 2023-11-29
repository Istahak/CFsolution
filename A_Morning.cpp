#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    string s;
    cin >> s;
    s = "1" + s;
    int ans = 0;
    for (int i = 1; i < 5; i++)
    {
        int a = s[i] - '0';
        int b = s[i - 1] - '0';
        if (a == 0)
            a = 10;
        if (b == 0)
            b = 10;
        ans += abs(a - b);
        ans++;
    }
    cout << ans << '\n';
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